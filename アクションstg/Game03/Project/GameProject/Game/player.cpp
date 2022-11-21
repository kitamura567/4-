#include "player.h"


#include "AnimData.h"
#include"Gun.h"
#include"Gauge.h"
//#include"Field.h"
#include "Map.h"
//#include"Effect.h"
//#include"Goal.h"
#include"Slash.h"
#include"Guard.h"
#include"Bullet.h"
//#include"Title.h"
//#include"END.h"

Player::Player(const CVector2D& pos, bool flip) :
	Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//m_img = COPY_RESOURCE("END", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = pos;

	//スクロール設定
	

	m_attack_no = rand();
	m_guard_no = rand();
	m_gun_no = rand();


	//中心位置設定
	m_img.SetCenter(16,16);
	m_img.SetSize(32, 32);
	m_rect = CRect(-16, -16, 16, 16);
	//反転フラグ
	m_flip = flip;
	m_state = eState_Idle;
	m_is_ground = true;
	m_rad = 32;
	m_damage_no = -1;
	m_hp = 100;
	Base::Add(m_gauge = new Gauge(0));
	//HP設定
	m_hp = m_max_hp = 1000;
}
Player::~Player()
{
	if (m_gauge)
		m_gauge->SetKill();
}
void Player::Update() {
	m_pos_old = 
	m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
	case eState_Gun:
		StateGun();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	case eState_Guard:
		StateGuard();
		break;
	
	}
	//落ちていたら落下中状態へ移行
	//if (m_is_ground && m_vec.y > GRAVITY * 4)
	//	m_is_ground = false;
	//重力による落下
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;



	//アニメーション更新
	m_img.UpdateAnimation();
	//スクロール設定
	//m_scroll.x = m_pos.x - 1280 / 2;
	//m_scroll.y = m_pos.y - 600;
	
	m_gauge->SetValue((float)m_hp / m_max_hp);
	m_gauge->m_pos = CVector2D(0, 0);

}

void Player::Draw() {
	//位置設定
	m_img.SetPos(m_pos);
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();

}
void Player::Collision(Base* b)
{

	switch (b->m_type) {
		/*case eType_Goal:
			if (Base::CollisionRect(this, b)) {

				//if (PUSH(CInput::eButton1)){
				//b->SetKill();

				//Base::Add(new END());
				//}
			}
			break;*/
			case eType_Field:
				if (Map* m = dynamic_cast<Map*>(b)) {
					int t = m->CollisionMap(m_pos);
					if (t != 0)
						m_pos = m_pos_old;
				}
				break;

	



				
			
	case eType_Guard:
		if (Guard* s = dynamic_cast<Guard*>(b)) {
			if (m_damage_no == s->GetGuardNo() && Base::CollisionRect(this, s)) {
				
				m_damage_no = s->GetGuardNo();
				m_hp -= 0;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
		}
		break;
	/*case eType_Gun:
		if (Gun s = dynamic_cast<Gun*>(b)) {
			if (m_damage_no == s->GetGunNo() && Base::CollisionRect(this, s)) {

				m_damage_no = s->GetGunNo();
				m_hp -= 0;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
		}
		break;*/

		
	/*case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			m_hp -= 1;
			if (m_hp < 0) {
				m_hp = 0;
				SetKill();
			}
		}
		break;*/
	case eType_Enemy_Attack:
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();
				m_hp -= 10;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				//Base::Add(new Effect("Effect_Blood",m_pos + CVector2D(0, -128), m_flip));
			}
		}break;

	}

}

void Player::Damage(int Attack)
{
	m_hp -= Attack;
	if (m_hp <= 0) {
		SetKill();
	}
}


void Player::StateIdle()
{
	const float move_speed = 6;
	//ジャンプ力
	const float jump_pow = 12;


	bool move_flag = false;
	if (HOLD(CInput::eLeft)) {
		m_pos.x -= move_speed;
		m_flip = true;
		move_flag = true;
	}
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}
	if (HOLD(CInput::eUp)) {
		m_pos.y -= move_speed;
		m_flip = true;
		move_flag = true;
	}
	if (HOLD(CInput::eDown)) {
		m_pos.y += move_speed;
		m_flip = false;
		move_flag = true;
	}
	if (PUSH(CInput::eButton1)) {
		//攻撃状態へ移行
		m_state = eState_Attack;
		m_attack_no++;
	}
	if (PUSH(CInput::eButton2)) {
		m_state = eState_Guard;
		m_guard_no++;
	}
	
	if (PUSH(CInput::eButton3)) {
		m_state = eState_Gun;
		m_gun_no++;
	}

	
	//移動中なら
	else
	{

		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}

void Player::StateAttack()
{
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-32, -32), m_flip, eType_Player_Attack, m_attack_no));

		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(32, -32), m_flip, eType_Player_Attack, m_attack_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}

}

void Player::StateDamage()
{
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player::StateDown()
{

	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		//Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));

		m_kill = true;
	}
}

void Player::StateGun()
{//攻撃アニメーションへ変更
	/*m_img.ChangeAnimation(eAnimAttack02, false);
	if (m_img.GetIndex() == 4) {
		if (m_flip) {
			Base::Add(new Gun(m_pos + CVector2D(-32, -32), m_flip, eType_Player_Gun, m_gun_no));
			
		}
		else {
			Base::Add(new Gun(m_pos + CVector2D(32, -32), m_flip, eType_Player_Gun, m_gun_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}*/
	
}

void Player::StateGuard()
{
	m_img.ChangeAnimation(eAnimGuard, false);
	//3番目のパターンなら
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Guard(m_pos + CVector2D(-64, -64), m_flip, eType_Guard, m_guard_no));
		}
		else {
			Base::Add(new Guard(m_pos + CVector2D(64, -64), m_flip, eType_Guard, m_guard_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}

}

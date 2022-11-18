#include "Enemy.h"
#include"AnimData.h"
//#include"Field.h"
#include"Slash.h"
#include"Effect.h"
//#include"Map.h"
//#include"trap.h"
#include "Bullet.h"
#include"Gauge.h"

void Enemy::StateWait()
{
	m_move_cnt += 1;
	if (m_move_cnt > 180) {
		m_state = eState_Idle;
		m_move_cnt = 0;
	}
}

void Enemy::StateIdle()
{
	//const float move_speed = 6;
	bool move_flag = false;
	//const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	
	int R = rand() % 3;
	switch (R)
	{
	case 0:
		m_state = eState_Move;
		break;
	case 1:
		m_state = eState_Rotato;
		break;
	case 2:
		m_state = eState_Wait;
		break;
	}
		
	
}

void Enemy::StateAttack()
{
	m_img.ChangeAnimation(eAnimAttack01, false);
	/*if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
	}*/
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Wait;
	}
}

void Enemy::StateDamage()
{
	m_img.ChangeAnimation(eAnimDamage, false);
	m_state = eState_Idle;
	
}
/*void trap::StateWait()
{
	m_img.ChangeAnimation(eAnimIdle);
	if (--m_cnt <= 0) {
		m_cnt = rand() % 120 + 180;
		m_state = eState_Idle;
	}
}*/

void Enemy::StateDown()
{
	m_img.ChangeAnimation(eAnimDown, false);
	m_kill = true;
	/*if (m_img.CheckAnimationEnd()) {
		//Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		m_kill = true;
	}*/
}

void Enemy::StateMove()
{
	//CVector2D DIR(sin(m_ang), cos(m_ang));
	//m_pos += DIR * 1.0;
	m_move_cnt += 1;
	if (m_move_cnt > 180) {
		m_state = eState_Idle;
		m_move_cnt = 0;
	}
}

void Enemy::StateRotato()
{
	//m_ang += DtoR(2);
	if (m_move_cnt == 1) {
		m_dir = rand() % 4;
	}
	m_move_cnt += 1;
	if (m_move_cnt > 180) {
		m_state = eState_Idle;
		m_move_cnt = 0;
	}
}

Enemy::Enemy(const CVector2D& p, bool flip) :
	Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.ChangeAnimation(0);
	 m_pos = p;
	m_img.SetCenter(32, 32);
	m_img.SetSize(64, 64);
	m_rect = CRect(-32, -32, 32, 32);
	m_flip = flip;
	m_attack_no = rand();
	m_damage_no = -1;
	m_hp = 200;
	m_dir = eUp;

	//Base::Add(m_gauge = new Gauge(0));
	//HP設定
	//m_hp = m_max_hp = 200;
}

void Enemy::Update()
{
	
	//m_pos_old = m_pos;
	/*if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	m_vec.y += GRAVITY;*/
	
	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {
		//ターゲットへのベクトル
		
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		
			//for(i=0;i<4;i++){
				if (m_cnt >= 60) {
					Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));
					Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 3));
					Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 2));
					Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 1));
					m_cnt = 0;
				}
			
		
	}


	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
	case eState_Attack:
		StateAttack();
		break;
	case eState_Damage:
		StateDamage();
		break;
	case eState_Down:
		StateDown();
		break;
	case eState_Wait:
		StateWait();
		break;
	case eState_Move:
		StateMove();
		break;
	case eState_Rotato:
		StateRotato();
		break;

	}
	m_img.ChangeAnimation(m_dir);
	m_img.UpdateAnimation();
	//m_gauge->SetValue((float)m_hp / m_max_hp);
	//m_gauge->m_pos = CVector2D(0, 0);
}

void Enemy::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();

}

void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			SetKill();
		}
		break;




		case eType_Player_Attack:
			if (Slash* s = dynamic_cast<Slash*>(b)) {
				if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
					m_damage_no = s->GetAttackNo();
					m_hp -= 50;
					if (m_hp <= 0) {
						m_state = eState_Down;

					}
					else {
						m_state = eState_Damage;
					}
					Base::Add(new Effect("Effect_ShotHit", m_pos + CVector2D(0, -16), m_flip));
				}

			}
			break;

	/*case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				//m_is_ground = true;
			}
		}
		break;*/
	}
}

void Enemy::Damage(int Attack)
{
	m_hp -= Attack;
	if (m_hp <= 0) {
		SetKill();
	}
}

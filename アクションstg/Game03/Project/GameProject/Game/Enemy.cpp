#include "Enemy.h"
#include"AnimData.h"
//#include"Field.h"
//#include"Slash.h"
//#include"Effect.h"
//#include"Map.h"
//#include"trap.h"
#include "Bullet.h"

void Enemy::StateIdle()
{
	//const float move_speed = 6;
	bool move_flag = false;
	//const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		if (player->m_pos.x < m_pos.x - 32) {
			//m_pos.x += -move_speed;
			m_flip = true;
			move_flag = true;
		}
		else
			if (player->m_pos.x > m_pos.x + 32) {
				//	m_pos.x += move_speed;
				m_flip = false;
				move_flag = true;
			}
		/*else {
			m_state = eState_Attack;
			m_attack_no++;

		}*/
		if (--m_cnt <= 0) {
			m_cnt = rand() % 120 + 180;
			m_state = eState_Wait;
		}
		if (move_flag) {
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			m_img.ChangeAnimation(eAnimIdle);
		}
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
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
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
	if (m_img.CheckAnimationEnd()) {
		//Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		m_kill = true;
	}
}

Enemy::Enemy(const CVector2D& p, bool flip) :
	Base(eType_Enemy) {
	m_img = COPY_RESOURCE("trap", CImage);
	m_img.ChangeAnimation(0);
	 m_pos = p;
	m_img.SetCenter(32, 32);
	m_img.SetSize(64, 64);
	m_rect = CRect(-32, -32, 32, 32);
	m_flip = flip;
	m_attack_no = rand();
	m_damage_no = -1;
	m_hp = 50;
}

void Enemy::Update()
{

	//m_pos_old = m_pos;
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 210) {
			//Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));

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

	}
	m_img.UpdateAnimation();
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





		/*case eType_Player_Attack:
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
					Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
				}

			}
			break;*/

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
#include "Bullet.h"
#include"Enemy.h"
#include"player.h"
#include"Guard.h"
#include"Map.h"

Bullet::Bullet(int type, const CVector2D& pos, float ang, float speed) : Base(type)
{
	m_img = COPY_RESOURCE("Bullet", CImage);
	m_pos = pos;

	m_ang = ang;
	m_speed = speed * 1;
	//	trap = trapbullet;
}

void Bullet::Update()
{

	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;

}
void Bullet::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Bullet::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(m_pos);
			if (t != 0)
				SetKill();
		}
		break;
	case eType_Guard:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			if (Player* p = dynamic_cast<Player*>(b)) {
				p->Damage(0);
			}

		}
		break;
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			if (Player* p = dynamic_cast<Player*>(b)) {
				p->Damage(10);
			}

		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			if (Enemy* p = dynamic_cast<Enemy*>(b)) {
				p->Damage(10);
			}

		}
		break;
	}
}

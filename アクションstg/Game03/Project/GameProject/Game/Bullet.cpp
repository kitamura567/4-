#include "Bullet.h"
#include"Enemy.h"

//#include"Map.h"

trapbullet::trapbullet(int type, const CVector2D& pos, float ang, float speed) : Base(type)
{
	m_img = COPY_RESOURCE("trapbullet", CImage);
	m_pos = pos;

	m_ang = ang;
	m_speed = speed * 1;
	//	trap = trapbullet;
}

void trapbullet::Update()
{

	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;

}
void trapbullet::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void trapbullet::Collision(Base* b)
{
	switch (b->m_type) {
	/*case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(m_pos);
			if (t != 0)
				SetKill();
		}
		break;*/
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;
	}
}

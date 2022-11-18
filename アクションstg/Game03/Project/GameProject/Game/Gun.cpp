#include "Gun.h"
#include"Enemy.h"
#include"player.h"

Gun::Gun(int type, const CVector2D& pos, float ang, float speed) :Base(type)
{
	if (type == eType_Player_Gun)
		m_img = COPY_RESOURCE("Gun", CImage);
	else
		m_img = COPY_RESOURCE("Gun2", CImage);
	m_pos = pos;
	
	m_ang = ang;
	m_speed = speed;
}
void Gun::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
	
	m_img.UpdateAnimation();
	//アニメーション終了チェック
	if (m_img.CheckAnimationEnd()) {
		//エフェクトを削除
		SetKill();
	}
}

void Gun::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

	
}

void Gun::Collision(Base* b)
{
	switch (b->m_type) {
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





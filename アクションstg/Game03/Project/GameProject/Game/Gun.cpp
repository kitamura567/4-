#include "Gun.h"

Gun::Gun(int type, const CVector2D& pos, float ang, float speed) :Base(type)
{
	if (type == eType_Player_Gun)
		m_img = COPY_RESOURCE("Gun", CImage);
	else
		m_img = COPY_RESOURCE("Gun2", CImage);
	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_ang = ang;
	m_speed = speed;
}
void Gun::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}

void Gun::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
	m_img.UpdateAnimation();
	
}

void Gun::Collision(Base* b)
{
}





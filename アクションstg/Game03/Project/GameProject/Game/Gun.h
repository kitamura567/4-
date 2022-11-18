#pragma once
#include "../Base/Base.h"

class Gun:public Base{
	CImage m_img;
	float m_speed;
	int m_gun_no;
public:
	Gun(int type, const CVector2D& pos,float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base*b);
	int GetGunNo() {
		return m_gun_no;
	}
};
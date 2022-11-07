#pragma once
#include "../Base/Base.h"

class Gun:public Base{
	CImage m_img;
	float m_speed;
public:
	Gun(int type, const CVector2D& pos,float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base*b);
};
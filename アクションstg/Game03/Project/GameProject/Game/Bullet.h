#pragma once

#include "../Base/Base.h"

class trapbullet : public Base {
	CImage m_img;
	float m_speed;
public:
	trapbullet(int type, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);
};
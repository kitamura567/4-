#pragma once
#include "../Base/Base.h"
class Gauge;
class Player : public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Gun,
		eState_Damage,
		eState_Down,
	};
	int m_attack_no;

	

	int m_state;
	int m_damage_no;
	int m_hp;
	int m_max_hp;
	CImage m_img;
	Gauge* m_gauge;
	bool	m_flip;
	bool	m_is_ground;

	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
	void StateGun();
public:
	Player(const CVector2D& p, bool flip);
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);
};
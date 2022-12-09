#pragma once


#include"../Base/Base.h"
//
class Enemy :public Base {
public:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Wait,
		eState_Move,
		eState_Rotato,
	};
	int m_state;
	int m_cnt;
	int m_move_cnt;
	CImage m_img;
	bool m_flip;
	bool m_is_ground;
	int i;
	int AIstate;

	int m_attack_no;
	int m_damage_no;
	int m_hp;
	int m_max_hp;
	//Gauge* m_gauge;

	void StateWait();
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
	void StateMove();
	void StateRotato();
public:
	Enemy(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
	void Damage(int Attack);
};
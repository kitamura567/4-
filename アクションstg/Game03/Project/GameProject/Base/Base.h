#pragma once
#include<GLLibrary.h>

#define  GRAVITY  (9.8f/20)
enum {
	eType_Field,
	eType_Player,
	eType_Enemy,
	eType_Enemy_Bullet,
	eType_Player_Bullet,
	eType_Bullet,
	eType_Goal,
	eType_Effect,
	eType_UI,
	eType_Player_Attack,
	eType_Enemy_Attack,
	eType_Scene,
};
class Base {
public:
	
	
	CVector2D m_vec;
	int m_type;
	CVector2D m_pos;
	static CVector2D m_scroll;
	static std::list<Base*>m_list;
	float m_ang;
	float m_rad;
	int	m_hit_id;
	bool m_kill;
	Base* Base::FindObject(int type);
	CRect m_rect;
	
public:
	void SetKill() { m_kill = true; }
	//â~ìØémÇÃè’ìÀ
	
	Base(int type);
	Base();
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);

	static bool CollisionRect(Base* b1, Base * b2);
	void DrawRect();
	static CVector2D GetScreenPos(const CVector2D& pos);
	static void CollisionAll();
	static void UpdateAll();
	static void DrawAll();
	static void Add(Base*);
	static void CheckKillAll();
	static void KillAll();
	static bool CollisionCircle(Base* b1, Base* b2);
	static std::list<Base*>FindObjects(int type);
};
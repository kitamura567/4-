#pragma once
#include "../Base/Base.h"

class Guard : public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//���]�t���O
	bool	m_flip;
	int m_guard_no;
public:
	Guard(const CVector2D& pos, bool flip, int type, int guard_no);
	void Update();
	void Draw();
	int GetGuardNo() {
		return m_guard_no;
	}
};

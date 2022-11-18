#pragma once
#include "../Base/Base.h"

class Guard : public Base {
private:
	//画像オブジェクト
	CImage m_img;
	//反転フラグ
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

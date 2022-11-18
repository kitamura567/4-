#include "Guard.h"

Guard::Guard(const CVector2D& pos, bool flip, int type, int guard_no):
Base(type)
{
	m_img = COPY_RESOURCE("Effect_Guard", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(128, 128);
	m_img.SetCenter(64, 64);
	m_rect = CRect(-64, -64, 64, 64);
	m_img.ChangeAnimation(0, false);
	m_guard_no = guard_no;
}

void Guard::Update()
{
	m_img.UpdateAnimation();
	//アニメーション終了チェック
	if (m_img.CheckAnimationEnd()) {
		//エフェクトを削除
		SetKill();
	}

}

void Guard::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();

}

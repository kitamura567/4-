#include "UI.h"

UI::UI() :Base(eType_UI) {
	m_img.Load("Image/UI.png");
}
void UI::Draw()
{
	Base* enemy = Base::FindObject(eType_Enemy);

	//敵がいなければ
	if (enemy == nullptr) {
		//ゲームクリアの表示
		m_img.SetRect(0, 64, 0 + 160, 64 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(300, 400);
		m_img.Draw();
	}

	
	
}

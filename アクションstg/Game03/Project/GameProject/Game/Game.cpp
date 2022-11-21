#include "Game.h"
#include "UI.h"
#include "Player.h"
#include "Enemy.h"
#include "Title.h"

Game::Game() :Base(eType_Scene)
{
	
	Base::Add(new Player(CVector2D(200, 500), false));
	Base::Add(new Enemy(CVector2D(800, 500), true));
	m_img.Load("Image/UI.png");
	

}
Game::~Game()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update()
{
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
		
	}
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}
	Base* enemy = Base::FindObject(eType_Enemy);
	Base* player = Base::FindObject(eType_Player);

	//敵がいなければ
	if (enemy == nullptr) {
		//ゲームクリアの表示
		m_img.SetRect(0, 64, 0 + 160, 64 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(300, 400);
		m_img.Draw();
	}
	if (player == nullptr) {
		//ゲームオーバーの表示
		m_img.SetRect(0, 96, 0 + 190, 96 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(300, 400);
		m_img.Draw();
	}

}

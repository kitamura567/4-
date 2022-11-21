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
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update()
{
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
		
	}
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}
	Base* enemy = Base::FindObject(eType_Enemy);
	Base* player = Base::FindObject(eType_Player);

	//�G�����Ȃ����
	if (enemy == nullptr) {
		//�Q�[���N���A�̕\��
		m_img.SetRect(0, 64, 0 + 160, 64 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(300, 400);
		m_img.Draw();
	}
	if (player == nullptr) {
		//�Q�[���I�[�o�[�̕\��
		m_img.SetRect(0, 96, 0 + 190, 96 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(300, 400);
		m_img.Draw();
	}

}

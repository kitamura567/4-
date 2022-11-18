#pragma once
#include "../Base/Base.h"

class Game : public Base {
public:
	CImage m_img;
	Game();
	~Game();
	void Update();
};

#pragma once
#include "../Base/Base.h"

class Text : public Base {
	static const int m_max_size = 256;
	static const int m_max_line = 32;
	char	m_text[m_max_line][m_max_size];
	int		m_line;
	int		m_line_size;
	CFont* m_font;
public:
	Text(const char* file, CFont* font);
	~Text();
	void Update();
	void Draw();
};
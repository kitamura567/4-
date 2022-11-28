#include "Text.h"

Text::Text(const char* file, CFont* font)
	:Base(eType_UI), m_font(nullptr)
{
	//ファイルポインタ
	FILE* fp;
	//ファイルを開く "r"テキスト読み込みモード
	fopen_s(&fp, file, "r");
	//開くのに失敗
	if (!fp) return;
	m_line = 0;
	m_line_size = 0;
	//ファイルの末尾まで繰り返す
	while (!feof(fp))
	{
		//一行読み込む
		fgets(m_text[m_line_size], m_max_size, fp);
		//改行まで読み込みので改行(\n)を消す
		char* p = strrchr(m_text[m_line_size], '\n');
		if (p) *p = '\0';

		m_line_size++;
	}
	fclose(fp);
	m_font = font;
}

Text::~Text()
{


}

void Text::Update()
{
	if (m_line < m_line_size) {
		//マウスクリックで次のテキストに
		if (PUSH(CInput::eMouseL)) {
			m_line++;
		}
	}
}

void Text::Draw()
{
	if (m_line < m_line_size) {
		//文字表示
		if (m_font) m_font->Draw(0, 600, 1, 1, 1, m_text[m_line]);
	}
}
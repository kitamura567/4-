#include "Text.h"

Text::Text(const char* file, CFont* font)
	:Base(eType_UI), m_font(nullptr)
{
	//�t�@�C���|�C���^
	FILE* fp;
	//�t�@�C�����J�� "r"�e�L�X�g�ǂݍ��݃��[�h
	fopen_s(&fp, file, "r");
	//�J���̂Ɏ��s
	if (!fp) return;
	m_line = 0;
	m_line_size = 0;
	//�t�@�C���̖����܂ŌJ��Ԃ�
	while (!feof(fp))
	{
		//��s�ǂݍ���
		fgets(m_text[m_line_size], m_max_size, fp);
		//���s�܂œǂݍ��݂̂ŉ��s(\n)������
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
		//�}�E�X�N���b�N�Ŏ��̃e�L�X�g��
		if (PUSH(CInput::eMouseL)) {
			m_line++;
		}
	}
}

void Text::Draw()
{
	if (m_line < m_line_size) {
		//�����\��
		if (m_font) m_font->Draw(0, 600, 1, 1, 1, m_text[m_line]);
	}
}
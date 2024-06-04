#include "InfoUiClass.h"

InfoUiClass::InfoUiClass()
{
	m_fps = 0;
	m_count = 0;
}

bool InfoUiClass::Initialize()
{
	m_startTime = timeGetTime();

	return true;
}

void InfoUiClass::Frame(TextClass* m_textclass)
{
	GetFps();
	string str = "FPS:";
	str = str + to_string(m_fps);
	wstring w_trans = wstring(str.begin(), str.end());
	m_textclass->BeginDraw();
	m_textclass->RenderText(w_trans.c_str(), 0, 0, 800, 400);
	m_textclass->EndDraw();
	return;
}

void InfoUiClass::GetFps()
{
	m_count++;

	if (timeGetTime() >= (m_startTime + 1000))
	{
		m_fps = m_count;
		m_count = 0;

		m_startTime = timeGetTime();
	}

	return;
}

void InfoUiClass::Shutdown()
{
	return;
}
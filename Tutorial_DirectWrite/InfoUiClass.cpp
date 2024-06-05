#include "InfoUiClass.h"

InfoUiClass::InfoUiClass()
{
	m_fps = 0;
	m_count = 0;
	m_startTime = 0;
}

bool InfoUiClass::Initialize(D3DClass* d3dClass)
{
	bool result;
	char videoCard[128];
	int videoMemory;

	d3dClass->GetVideoCardInfo(videoCard, videoMemory);

	wcscpy_s(m_videoNameString, L"");
	MultiByteToWideChar(CP_ACP, 0, videoCard, strlen(videoCard) + 1, m_videoNameString, _countof(m_videoNameString));
	//wchar_t용 Itoa, 마지막 매개변수는 10진수를 뜻함 기본 16진수이므로 꼭 10 써줘야 함
	_itow_s(videoMemory, m_tempString, _countof(m_tempString), 10); 

	wcscpy_s(m_memoryString, L"VRAM: ");
	wcscat_s(m_memoryString, m_tempString);
	wcscat_s(m_memoryString, L" MB");

	return true;
}

void InfoUiClass::Frame(TextClass* m_textclass)
{
	m_textclass->BeginDraw();
	//GetFps();

	////Fps를 출력하는 부분
	//wcscpy_s(m_fpsString, L"FPS: ");
	//_itow_s(m_fps, m_tempString, _countof(m_tempString), 10);
	//wcscat_s(m_fpsString, m_tempString);
	//m_textclass->RenderText(m_fpsString, 0, 0, 800, 400);


	////비디오 카드 정보를 출력하는 부분
	//m_textclass->RenderText(m_videoNameString, 0, 30, 800, 400);
	//m_textclass->RenderText(m_memoryString, 0, 60, 800, 400);


	//카메라 위치 정보를 출력하는 부분


	m_textclass->RenderText(L"다람쥐 헌 챗바퀴에 타고파", 0, 0, 800, 400);
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
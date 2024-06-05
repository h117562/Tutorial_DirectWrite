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
	//wchar_t�� Itoa, ������ �Ű������� 10������ ���� �⺻ 16�����̹Ƿ� �� 10 ����� ��
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

	////Fps�� ����ϴ� �κ�
	//wcscpy_s(m_fpsString, L"FPS: ");
	//_itow_s(m_fps, m_tempString, _countof(m_tempString), 10);
	//wcscat_s(m_fpsString, m_tempString);
	//m_textclass->RenderText(m_fpsString, 0, 0, 800, 400);


	////���� ī�� ������ ����ϴ� �κ�
	//m_textclass->RenderText(m_videoNameString, 0, 30, 800, 400);
	//m_textclass->RenderText(m_memoryString, 0, 60, 800, 400);


	//ī�޶� ��ġ ������ ����ϴ� �κ�


	m_textclass->RenderText(L"�ٶ��� �� ê������ Ÿ����", 0, 0, 800, 400);
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
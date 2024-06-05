#ifndef _INFO_UICLASS_H_
#define _INFO_UICLASS_H_

#include <Windows.h>
#include <wchar.h>
#include "textclass.h"

class InfoUiClass
{
public:
	InfoUiClass();

	bool Initialize(D3DClass*);
	void Frame(TextClass*);
	void Shutdown();
private:
	void GetFps();

private:
	int m_fps, m_count;
	wchar_t m_fpsString[20];
	wchar_t m_videoNameString[144];
	wchar_t m_memoryString[32];
	wchar_t m_tempString[16];//Int에서 Char로 바꾸기 위함
	unsigned long m_startTime;
};

#endif
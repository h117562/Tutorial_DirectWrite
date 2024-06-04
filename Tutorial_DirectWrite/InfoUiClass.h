#ifndef _INFO_UICLASS_H_
#define _INFO_UICLASS_H_

#include <Windows.h>
#include "textclass.h"

class InfoUiClass
{
public:
	InfoUiClass();

	bool Initialize();
	void Frame(TextClass*);
	void Shutdown();
private:
	void GetFps();

private:
	int m_fps, m_count;
	unsigned long m_startTime;
};

#endif
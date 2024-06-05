#ifndef _APPLICATION_CLASS_H_
#define _APPLICATION_CLASS_H_

#include <Windows.h>
#include "D3DClass.h"
#include "ColorShaderClass.h"
#include "CameraClass.h"
#include "ModelClass.h"
#include "InfoUiClass.h"
#include "TextClass.h"


class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(HINSTANCE, HWND, bool V_SYNC, bool FullScreen, float ScreenDepth, float ScreenNear);
	void Shutdown();
	bool Frame();

private:
	D3DClass* m_Direct3D;
	ColorShaderClass* m_ColorShader;
	CameraClass* m_CameraClass;
	ModelClass* m_ModelClass;
	InfoUiClass* m_InfoUi;
	TextClass* m_TextClass;
};
#endif
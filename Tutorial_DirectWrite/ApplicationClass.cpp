#include "ApplicationClass.h"

ApplicationClass::ApplicationClass()
{
	m_Direct3D = 0;
	m_ColorShader = 0;
	m_CameraClass = 0;
	m_ModelClass = 0;
	m_InfoUi = 0;
	m_TextClass = 0;
}

ApplicationClass::~ApplicationClass()
{

}

bool ApplicationClass::Initialize(HINSTANCE hinstance, HWND hwnd, bool vsyncEnabled, bool fullScreen, float screenDepth, float screenNear, float screenWidth, float screenHeight)
{
	bool result;

	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	result = m_Direct3D->Initialize(vsyncEnabled, hwnd, fullScreen, screenDepth, screenNear, screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	m_ColorShader = new ColorShaderClass;
	if (!m_ColorShader)
	{
		return false;
	}

	result = m_ColorShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the ShaderClass.", L"Error", MB_OK);
		return false;
	}

	m_TextClass = new TextClass;
	if (!m_TextClass)
	{
		return false;
	}

	result = m_TextClass->Initialize(m_Direct3D);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the TextClass.", L"Error", MB_OK);
		return false;
	}

	m_InfoUi = new InfoUiClass;
	if (!m_InfoUi)
	{
		return false;
	}

	result = m_InfoUi->Initialize();
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the InfoUiClass.", L"Error", MB_OK);
		return false;
	}

	m_ModelClass = new ModelClass;
	if (!m_ModelClass)
	{
		return false;
	}

	result = m_ModelClass->Initialize(m_Direct3D->GetDevice());
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the Triangle.", L"Error", MB_OK);
		return false;
	}

	m_CameraClass = new CameraClass;
	if (!m_CameraClass)
	{
		return false;
	}

	m_CameraClass->SetPosition(0.0f, 0.0f, -10.0f);

	return result;
}

void ApplicationClass::Shutdown()
{
	if (m_InfoUi)
	{
		m_InfoUi->Shutdown();
		delete m_InfoUi;
		m_InfoUi = 0;
	}

	if (m_TextClass)
	{
		m_TextClass->Shutdown();
		delete m_TextClass;
		m_TextClass = 0;
	}

	if (m_CameraClass)
	{
		delete m_CameraClass;
		m_CameraClass = 0;
	}

	if (m_ModelClass)
	{
		m_ModelClass->Shutdown();
		delete m_ModelClass;
		m_ModelClass = 0;
	}

	if (m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}
}

bool ApplicationClass::Frame()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;

	m_CameraClass->Render();
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_CameraClass->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);
	m_Direct3D->GetOrthoMatrix(orthoMatrix);

	//백 버퍼 초기화
	m_Direct3D->BeginScene(0.7f, 1.0f, 1.0f, 1.0f);

	m_ModelClass->Render(m_Direct3D->GetDeviceContext());
	result = m_ColorShader->Render(m_Direct3D->GetDeviceContext(), m_ModelClass->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	m_InfoUi->Frame(m_TextClass);

	m_Direct3D->EndScene();

	return true;
}
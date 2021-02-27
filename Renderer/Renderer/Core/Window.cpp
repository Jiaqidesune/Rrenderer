#include "Window.h"
#include <windowsx.h>

namespace kawaii
{
	Setting* Window::m_setting = new Setting();

	LRESULT CALLBACK Window::MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_KEYDOWN:
			m_setting->receiveKeyEvent('S');
			break;
		case WM_KEYUP:
			m_setting->receiveKeyEvent('W');
			break;
		case WM_LBUTTONDOWN:
			m_setting->receiveMouseEvent(static_cast<float>(GET_X_LPARAM(lParam)), static_cast<float>(GET_Y_LPARAM(lParam)), "LEFT");
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
			m_setting->receiveMouseEvent(static_cast<float>(GET_X_LPARAM(lParam)), static_cast<float>(GET_Y_LPARAM(lParam)), "RIGHT");
			break;
		case WM_RBUTTONUP:
		case WM_MOUSEWHEEL:
			m_setting->receiveMouseWheelEvent(GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA);
			break;

		default: return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		return 0;
	}

	const wchar_t* Window::ClassName = L"MyWindow";

	Window::Window(HINSTANCE hInstance, const wchar_t* title, UINT width, UINT height)
		:m_HInstance{ hInstance }, m_Title{ title }, m_Width{ width }, m_Height{ height }
	{

	}

	Window::~Window()
	{
		if (m_HWnd)
		{
			DestroyWindow(m_HWnd);
		}
		UnregisterClass(ClassName, m_HInstance);
	}

	bool Window::Init()
	{
		if (RegisterWindowClass() != 0)
		{
			return false;
		}

		if (CreateWindowInstance() != 0)
		{
			return false;
		}

		SetWindowLongPtr(m_HWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

		ShowWindow(m_HWnd, SW_SHOWDEFAULT);
		UpdateWindow(m_HWnd);

		return true;
	}

	int Window::Run()
	{
		MSG msg = {};
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		return (int)msg.wParam;
	}

	LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		auto myWindow = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

		switch (msg)
		{
		case WM_KEYUP:
			if (wParam == VK_ESCAPE)
			{
				PostQuitMessage(0);
			}
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	int Window::RegisterWindowClass()
	{
		WNDCLASSEXW wcex = {};
		wcex.cbSize = sizeof(WNDCLASSEXW);			// the size, in bytes, of the structure
		wcex.style = CS_HREDRAW | CS_VREDRAW;		// the class style, CS_HREDRAW specifies that the entire window is redrawn 
													// if a movement or size adjustment changes the width of the client area
		wcex.hInstance = m_HInstance;				// a handle to the instance that contains the window procudure for the class
		wcex.lpfnWndProc = (WNDPROC)MainWndProc; 	// MainWndProc	WindowProc	// a pointer to the window procedure that will handle window messages for any window created using this window class
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	// a handle to the clas background brush
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.lpszClassName = ClassName;
		wcex.lpszMenuName = nullptr;

		if (!RegisterClassEx(&wcex))
		{
			OutputDebugString(L"Create Window Class Failed!");
			return 1;
		}

		return 0;
	}

	int Window::CreateWindowInstance()
	{
		UINT width = m_Width, height = m_Height;
		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

		HWND hwnd = CreateWindowEx(
			0,
			ClassName,
			m_Title,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rect.right - rect.left,
			rect.bottom - rect.top,
			nullptr,
			nullptr,
			m_HInstance,
			nullptr
		);

		if (!hwnd)
		{
			OutputDebugString(L"Create Window Failed!");
			return 1;
		}

		m_HWnd = hwnd;

		return 0;
	}
}
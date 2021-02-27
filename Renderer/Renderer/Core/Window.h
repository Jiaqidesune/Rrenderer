#pragma once
#include <Windows.h>
#include "../Setting/Setting.h"

namespace kawaii
{
	
	class Window
	{
	public:
		static const wchar_t* ClassName;
		static LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
		Window(HINSTANCE hInstance, const wchar_t* title = L"Hello, World!", UINT width = 800, UINT height = 800);
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		~Window();
		bool Init();
		int Run();

		HWND GetWindow() const
		{
			return m_HWnd;
		}

		const wchar_t* GetWindowTitle() const
		{
			return m_Title;
		}

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		int RegisterWindowClass();
		int CreateWindowInstance();

		HINSTANCE m_HInstance;
		HWND m_HWnd = NULL;

		UINT m_Width;
		UINT m_Height;
		const wchar_t* m_Title;
		
		static Setting* m_setting;
	};

}
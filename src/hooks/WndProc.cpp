#include <pch.h>
#include <base.h>

LRESULT CALLBACK Base::Hooks::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(uMsg == WM_KEYDOWN || uMsg == WM_KEYUP)
		Data::WmKeys[wParam] = uMsg;

	if (uMsg == WM_KEYDOWN)
	{
		switch (wParam)
		{
		case Data::Keys::ToggleMenu:
			Data::ShowMenu = !Data::ShowMenu;
			break;
		case Data::Keys::DetachDll:
			Data::ToDetach = true;
			break;
		}
	}

	if (!Data::InputState)
		nk_input_begin(Data::ctx);

	nk_d3d9_handle_event(hWnd, uMsg, wParam, lParam);

	return CallWindowProc(Data::oWndProc, hWnd, uMsg, wParam, lParam);
}
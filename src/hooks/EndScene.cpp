#include <pch.h>
#include <base.h>

HRESULT __stdcall Base::Hooks::EndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (Data::InputState)
	{
		nk_input_end(Data::ctx);
		Data::InputState = false;
	}

	Data::pDxDevice9 = pDevice;
	if (!Data::InitNuklear && Data::pDxDevice9)
	{
		D3DVIEWPORT9 viewport;
		pDevice->GetViewport(&viewport);
		Data::ctx = nk_d3d9_init(Data::pDxDevice9, viewport.Width, viewport.Height);
		struct nk_font_atlas* atlas;
		nk_d3d9_font_stash_begin(&atlas);
		nk_d3d9_font_stash_end();
		Data::InitNuklear = true;
	}

	if (!Data::InitNuklear) return Data::oEndScene(pDevice);

	if (Data::ShowMenu)
	{
		nk_begin(Data::ctx, "Nuklear Window", nk_rect(0, 0, 400, 250), NK_WINDOW_MOVABLE | NK_WINDOW_TITLE);
		nk_label(Data::ctx, "Test Window", NK_TEXT_ALIGN_LEFT);
		nk_button_label(Data::ctx, "Test");

		nk_end(Data::ctx);

		nk_d3d9_render(NK_ANTI_ALIASING_ON);
	}

	if(Data::ToDetach)
		Base::Detach();
	return Data::oEndScene(pDevice);
}
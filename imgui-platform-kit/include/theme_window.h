#pragma once

#include "user_interface_window.h"
#include "themes.h"

namespace imgui_kit
{
	class ThemeWindow : public UserInterfaceWindow
	{
		void render() override;
	};
}
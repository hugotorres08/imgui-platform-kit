#pragma once

#include "user_interface_window.h"
#include "log_window.h"

namespace imgui_kit
{
	class TemplateWindow : public UserInterfaceWindow
	{
	private:
		void render() override;
	};
}
#include "template_window.h"

#include "themes.h"

namespace imgui_kit
{
	void TemplateWindow::render()
	{
		if (ImGui::Begin("Hello, world!"))
		{
			ImGui::Text("This is some useful text.");
			ImGui::Button("Button");
		}
		ImGui::End();

		ImGuiWindowFlags flags = imgui_kit::getGlobalWindowFlags();

		// You can still add window-specific flags if needed:
		flags |= ImGuiWindowFlags_MenuBar; // This window needs a menu bar

		if (ImGui::Begin("My Window", nullptr, flags))
		{
			ImGui::Text("This window uses global flags!");
		}
		ImGui::End();

		ImGui::ShowDemoWindow();
		ImGui::ShowStyleEditor();
		ImPlot::ShowDemoWindow();
		static bool show = true;
		imgui_kit::showImGuiKitThemeSelector(&show);
	}
}

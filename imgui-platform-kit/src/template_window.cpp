#include "template_window.h"

#include "themes.h"

namespace imgui_kit
{
	void TemplateWindow::render()
	{
		ImGui::Begin("Hello, world!");
		ImGui::Text("This is some useful text.");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();
		ImGui::ShowStyleEditor();
		ImPlot::ShowDemoWindow();
		static bool show = true;
		imgui_kit::showImGuiKitThemeSelector(&show);
	}
}

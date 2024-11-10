#include "template_window.h"

namespace imgui_kit
{
	void TemplateWindow::render()
	{
		ImGui::Begin("Hello, world!");
		ImGui::Text("This is some useful text.");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();
		ImPlot::ShowDemoWindow();
	}
}

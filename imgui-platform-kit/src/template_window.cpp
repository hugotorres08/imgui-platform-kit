#include "template_window.h"

namespace imgui_kit
{

    

	void TemplateWindow::render()
	{
		static     ImNodeEditor::Config config;
		config.SettingsFile = "simple.json";
		static auto     context = ImNodeEditor::CreateEditor(&config);

		ImGui::Begin("Hello, world!");
		ImGui::Text("This is some useful text.");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();
		ImPlot::ShowDemoWindow();

		if (ImGui::Begin("Node graph", nullptr, 
			ImGuiWindowFlags_NoScrollbar |
			ImGuiWindowFlags_NoScrollWithMouse
			))
		{
			ImNodeEditor::SetCurrentEditor(context);
			auto& io = ImGui::GetIO();
			ImGui::Text("FPS: %.2f (%.2gms)", io.Framerate, io.Framerate ? 1000.0f / io.Framerate : 0.0f);
			ImNodeEditor::Begin("My Node ImNodeEditor");

			int uniqueId = 1;

			// Start a new node
			ImNodeEditor::BeginNode(uniqueId);
			ImGui::Text("Node A");
			ImNodeEditor::SetNodePosition(uniqueId++, ImVec2(100, 100));
			ImNodeEditor::BeginPin(uniqueId++, ImNodeEditor::PinKind::Input);
			ImGui::Text("-> Input");
			ImNodeEditor::EndPin();
			ImNodeEditor::BeginPin(uniqueId++, ImNodeEditor::PinKind::Output);
			ImGui::Text("Output ->");
			ImNodeEditor::EndPin();
			ImNodeEditor::EndNode();

			// Another node
			ImNodeEditor::BeginNode(uniqueId);
			ImNodeEditor::SetNodePosition(uniqueId++, ImVec2(200, 200));
			ImGui::Text("Node B");
			ImNodeEditor::BeginPin(uniqueId++, ImNodeEditor::PinKind::Input);
			ImGui::Text("-> Input");
			ImNodeEditor::EndPin();
			ImNodeEditor::BeginPin(uniqueId, ImNodeEditor::PinKind::Output);
			ImGui::Text("Output ->");
			ImNodeEditor::EndPin();
			ImNodeEditor::EndNode();

			ImNodeEditor::End();
			ImNodeEditor::SetCurrentEditor(nullptr);
		}
		ImGui::End();



	}
}

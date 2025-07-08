#include "log_window.h"

namespace imgui_kit
{
	LogWindow::LogWindow()
	{
   		isWindowActive = true;
		clean();
	}

	void LogWindow::addLog(const ImVec4& color, const char* fmt, ...)
	{
   		va_list args;
		va_start(args, fmt);
		char buffer[1024];
		vsnprintf(buffer, IM_ARRAYSIZE(buffer), fmt, args);
		buffer[IM_ARRAYSIZE(buffer) - 1] = '\0';
		 va_end(args);
		logs.push_back({ buffer, color });
	}

	void LogWindow::draw()
	{
        if (!ImGui::Begin("Log Window", &isWindowActive)) 
        {
            ImGui::End();
            return;
        }

        if (ImGui::BeginPopup("Options")) 
        {
            ImGui::Checkbox("Auto-scroll", &autoScroll);
            ImGui::EndPopup();
        }

        if (ImGui::Button("Options")) 
            ImGui::OpenPopup("Options");
        ImGui::SameLine();
        if (ImGui::Button("Clear"))
            clean();
        ImGui::SameLine();
        if (ImGui::Button("Copy"))
            ImGui::LogToClipboard();
        ImGui::SameLine();
        filter.Draw("Filter", -100.0f);

        ImGui::Separator();
        if (ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar)) 
        {
            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
            for (const auto& [message, color] : logs)
            {
                if (filter.PassFilter(message.c_str())) 
                {
                    ImGui::PushStyleColor(ImGuiCol_Text, color);
                    ImGui::TextEx(message.c_str());
                    ImGui::PopStyleColor();
                }
            }
            ImGui::PopStyleVar();

            if (autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) 
                ImGui::SetScrollHereY(1.0f);
        }
        ImGui::EndChild();
        ImGui::End();
	}

} 
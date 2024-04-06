#pragma once

#include <algorithm>
#include <stdexcept>

#include "imgui.h"

namespace imgui_kit
{
	namespace win32_directx12
	{
		struct WindowParameters
		{
			std::wstring title;
			int width;
			int height;

			WindowParameters(std::wstring windowTitle = L"default title", int width = 1280, int height = 720);
		};

		struct FontParameters
		{
			std::string path;
			int size;

			FontParameters(std::string path, int size = 12);
		};

		constexpr ImVec4 defaultThemeColor = ImVec4(0.0f, 0.5f, 1.0f, 1.0f); // A vibrant blue

		struct StyleParameters
		{
			ImVec4 windowBgColor;
			float windowRounding;
			ImVec2 windowPadding;
			float transparency;
			ImVec4 textColor;
			ImVec4 themeColor;

			StyleParameters()
				: themeColor(defaultThemeColor)
			{
				windowBgColor = ImVec4(themeColor.x * 0.3f, themeColor.y * 0.3f, themeColor.z * 0.3f, themeColor.w);
				windowRounding = 5.0f;
				windowPadding = ImVec2(8.0f, 8.0f);
				transparency = 1.0f;
				textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
			}


			StyleParameters(ImVec4 themeColor)
				: themeColor(themeColor)
			{
				windowBgColor = ImVec4(themeColor.x * 0.8f, themeColor.y * 0.8f, themeColor.z * 0.8f, themeColor.w);
				windowRounding = 5.0f;
				windowPadding = ImVec2(8.0f, 8.0f);
				transparency = 1.0f;
				textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
			}

			void apply()
			{
				ImGuiStyle& style = ImGui::GetStyle();
				style.WindowPadding = windowPadding;
				style.WindowRounding = windowRounding;
				style.Alpha = transparency;
				style.Colors[ImGuiCol_WindowBg] = windowBgColor;
				style.Colors[ImGuiCol_Text] = textColor;

				// Set other UI elements based on the theme color
				// Example adjustments for some other UI elements:

				// Slightly darker for window header/background
				ImVec4 headerBgColor = ImVec4(themeColor.x * 0.9f, themeColor.y * 0.9f, themeColor.z * 0.9f, themeColor.w);

				// Even darker for active elements to give a pressed feel
				ImVec4 activeElementColor = ImVec4(themeColor.x * 0.7f, themeColor.y * 0.7f, themeColor.z * 0.7f, themeColor.w);

				// A lighter version for hovered elements to indicate interactability
				ImVec4 hoveredElementColor = ImVec4(themeColor.x * 1.1f, themeColor.y * 1.1f, themeColor.z * 1.1f, themeColor.w);

				// Applying calculated colors
				style.Colors[ImGuiCol_TitleBg] = headerBgColor;
				style.Colors[ImGuiCol_TitleBgActive] = headerBgColor;
				style.Colors[ImGuiCol_Button] = themeColor;
				style.Colors[ImGuiCol_ButtonHovered] = hoveredElementColor;
				style.Colors[ImGuiCol_ButtonActive] = activeElementColor;
				style.Colors[ImGuiCol_Header] = themeColor;
				style.Colors[ImGuiCol_HeaderHovered] = hoveredElementColor;
				style.Colors[ImGuiCol_HeaderActive] = activeElementColor;
				// Additional elements can be themed in a similar manner
			}
		};

		struct UserInterfaceParameters
		{
			WindowParameters windowParameters;
			FontParameters fontParameters;
			StyleParameters styleParameters;

			UserInterfaceParameters(WindowParameters windowParameters, 
				FontParameters fontParameters);
			UserInterfaceParameters(WindowParameters windowParameters, 
				FontParameters fontParameters, 
				const StyleParameters& styleParameters);
		};
	}
}
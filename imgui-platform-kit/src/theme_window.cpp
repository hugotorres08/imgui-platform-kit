#include "theme_window.h"


namespace imgui_kit
{
	void ThemeWindow::render()
	{
        static Theme selectedTheme =Theme::Dark;

        if (ImGui::Begin("Style Editor"))
        {
            const char* currentThemeName = themeNames.at(selectedTheme).c_str();
        	if (ImGui::BeginCombo("Select Theme", currentThemeName))
            {
                for (const auto& [theme, themeName] : themeNames)
                {
                    const bool isSelected = (selectedTheme == theme);
                    if (ImGui::Selectable(themeName.c_str(), isSelected))
                    {
                        if (!isSelected) 
                        {
                            selectedTheme = theme; 
                            themes[theme]();
                        }
                    }
                    if (isSelected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }
        }
        ImGui::End();
	}
}

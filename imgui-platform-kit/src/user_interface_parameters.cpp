#include "user_interface_parameters.h"

namespace imgui_kit
{
	WindowParameters::WindowParameters(std::string title, int width, int height, int startPosX, int startPosY)
		: title(std::move(title)), width(width), height(height), startPosX(startPosX), startPosY(startPosY)
	{
		load();
#if defined(_WIN32)
		if (this->width <= 0 || this->height <= 0)
		{
			const HMONITOR hMonitor = MonitorFromWindow(nullptr, MONITOR_DEFAULTTOPRIMARY);
			MONITORINFO mi = { sizeof(mi) };
			if (GetMonitorInfo(hMonitor, &mi))
			{
				this->width = mi.rcMonitor.right - mi.rcMonitor.left;
				this->height = mi.rcMonitor.bottom - mi.rcMonitor.top;
			}
			else
			{
				RECT desktop;
				const HWND hDesktop = GetDesktopWindow();
				GetWindowRect(hDesktop, &desktop);
				this->width = desktop.right;
				this->height = desktop.bottom;
			}
		}
#elif defined(__linux__)
		if (this->width <= 0 || this->height <= 0)
		{
			if (!glfwInit())
				throw std::runtime_error("Failed to initialize GLFW.");

			// Get the primary monitor
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			if (primaryMonitor == nullptr)
				throw std::runtime_error("Failed to get the primary monitor.");

			// Get the current video mode of the monitor
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			if (mode == nullptr)
				throw std::runtime_error("Failed to get the video mode of the primary monitor.");

			// Set width and height to the monitor's resolution if they were invalid
			this->width = mode->width;
			this->height = mode->height;

			glfwTerminate();
		}
#endif

		if (this->width <= 0)  
			throw std::invalid_argument("Width must be greater than 0.");
		if (this->height <= 0)  
			throw std::invalid_argument("Height must be greater than 0.");
	}

	void WindowParameters::save(const std::string& filename) const
	{
		std::ofstream file(filename);
		if (!file.is_open())
			throw std::runtime_error("Could not open file for writing.");

		file << "[Window Parameters]\n";
		file << "Title=" << title << "\n";
		file << "Width=" << width << "\n";
		file << "Height=" << height << "\n";
		file << "StartPosX=" << startPosX << "\n";
		file << "StartPosY=" << startPosY << "\n";

		file.close();
		if (file.fail())
			throw std::runtime_error("Failed to save window parameters.");
	}

	void WindowParameters::load(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file.is_open())
			return; // If the file does not exist, skip loading

		std::string line;
		while (std::getline(file, line))
		{
			if (line.find("Title=") == 0)
				title = line.substr(6);
			else if (line.find("Width=") == 0)
				width = std::stoi(line.substr(6));
			else if (line.find("Height=") == 0)
				height = std::stoi(line.substr(7));
			else if (line.find("StartPosX=") == 0)
				startPosX = std::stoi(line.substr(10));
			else if (line.find("StartPosY=") == 0)
				startPosY = std::stoi(line.substr(10));
		}

		file.close();
	}

	FontParameters::FontParameters(std::string path, int size)
		: path(std::move(path))
		, size(size)
	{
		if (size <= 0)
			throw std::invalid_argument("Size must be greater than 0.");
	}

	StyleParameters::StyleParameters()
		: themeColor(defaultThemeColor)
	{
		windowBgColor = ImVec4(themeColor.x * 0.8f, themeColor.y * 0.8f, themeColor.z * 0.8f, themeColor.w);
		windowRounding = 5.0f;
		windowPadding = ImVec2(8.0f, 8.0f);
		transparency = 1.0f;
		textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	StyleParameters::StyleParameters(ImVec4 themeColor)
		: themeColor(themeColor)
	{
		windowBgColor = ImVec4(themeColor.x * 0.8f, themeColor.y * 0.8f, themeColor.z * 0.8f, themeColor.w);
		windowRounding = 5.0f;
		windowPadding = ImVec2(8.0f, 8.0f);
		transparency = 1.0f;
		textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	StyleParameters::StyleParameters(ImVec4 themeColor, ImVec4 bgColor)
		: themeColor(themeColor), windowBgColor(bgColor)
	{
		windowRounding = 5.0f;
		windowPadding = ImVec2(8.0f, 8.0f);
		transparency = 1.0f;
		textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	void StyleParameters::apply() const
	{
		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowPadding = windowPadding;
		style.WindowRounding = windowRounding;
		style.Alpha = transparency;
		style.Colors[ImGuiCol_WindowBg] = windowBgColor;
		style.Colors[ImGuiCol_Text] = textColor;

		// Derive other colors from themeColor
		const ImVec4 base = themeColor; // Base theme color for reference
		const ImVec4 dark = ImVec4(base.x * 0.6f, base.y * 0.6f, base.z * 0.6f, base.w); // Darker variant
		const ImVec4 darker = ImVec4(base.x * 0.4f, base.y * 0.4f, base.z * 0.4f, base.w); // Even darker
		const ImVec4 light = ImVec4(base.x * 1.2f, base.y * 1.2f, base.z * 1.2f, base.w); // Lighter variant
		const ImVec4 lighter = ImVec4(base.x * 1.4f, base.y * 1.4f, base.z * 1.4f, base.w); // Even lighter
		const ImVec4 disabled = ImVec4(base.x * 0.5f, base.y * 0.5f, base.z * 0.5f, base.w); // Disabled / grayed
		const ImVec4 highlight = ImVec4(base.x * 0.7f, base.y * 0.7f, base.z * 0.7f, base.w); // Highlighted / active

		// Setting up colors
		style.Colors[ImGuiCol_TextDisabled] = disabled;
		style.Colors[ImGuiCol_TextSelectedBg] = dark;
		style.Colors[ImGuiCol_WindowBg] = base; // Main background
		style.Colors[ImGuiCol_ChildBg] = base; // Child window background
		style.Colors[ImGuiCol_PopupBg] = base; // Popup background
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f); // Border shadow (transparent)
		style.Colors[ImGuiCol_FrameBg] = dark;
		style.Colors[ImGuiCol_FrameBgHovered] = highlight;
		style.Colors[ImGuiCol_FrameBgActive] = darker;
		style.Colors[ImGuiCol_TabUnfocused] = dark;
		style.Colors[ImGuiCol_DockingEmptyBg] = darker; // Empty docking background
		style.Colors[ImGuiCol_PlotLines] = light;
		style.Colors[ImGuiCol_PlotLinesHovered] = lighter;
		style.Colors[ImGuiCol_PlotHistogram] = light;
		style.Colors[ImGuiCol_PlotHistogramHovered] = lighter;
		style.Colors[ImGuiCol_Separator] = dark;
		style.Colors[ImGuiCol_SeparatorHovered] = highlight;
		style.Colors[ImGuiCol_SeparatorActive] = darker;
		style.Colors[ImGuiCol_ResizeGrip] = base;
		style.Colors[ImGuiCol_ResizeGripHovered] = highlight;
		style.Colors[ImGuiCol_ResizeGripActive] = darker;
		style.Colors[ImGuiCol_TabUnfocusedActive] = darker;
		style.Colors[ImGuiCol_DockingPreview] = light; // Docking preview overlay
		style.Colors[ImGuiCol_Button] = dark;
		style.Colors[ImGuiCol_ButtonHovered] = highlight;
		style.Colors[ImGuiCol_ButtonActive] = darker;
		style.Colors[ImGuiCol_TitleBg] = dark;
		style.Colors[ImGuiCol_TitleBgActive] = highlight;
		style.Colors[ImGuiCol_TitleBgCollapsed] = base;
		style.Colors[ImGuiCol_Header] = dark;
		style.Colors[ImGuiCol_HeaderHovered] = highlight;
		style.Colors[ImGuiCol_HeaderActive] = darker;
		style.Colors[ImGuiCol_Tab] = dark;
		style.Colors[ImGuiCol_TabHovered] = highlight;
		style.Colors[ImGuiCol_TabActive] = darker;
		style.Colors[ImGuiCol_Border] = ImVec4(dark.x, dark.y, dark.z, 0.6f);  // Muted border
		style.Colors[ImGuiCol_MenuBarBg] = dark;                               // Menu bar background
		style.Colors[ImGuiCol_ScrollbarBg] = darker;                           // Scrollbar background
		style.Colors[ImGuiCol_ScrollbarGrab] = dark;                           // Scrollbar grab
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = highlight;               // Scrollbar grab hover
		style.Colors[ImGuiCol_ScrollbarGrabActive] = darker;                   // Scrollbar grab active
		style.Colors[ImGuiCol_CheckMark] = ImVec4(light.x * 1.1f, light.y * 1.3f, light.z * 1.5f, 1.0f); // Accent checkmark
		style.Colors[ImGuiCol_SliderGrab] = light;
		style.Colors[ImGuiCol_SliderGrabActive] = lighter;
		style.Colors[ImGuiCol_TableHeaderBg] = dark;
		style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(dark.x * 0.9f, dark.y * 0.9f, dark.z * 0.9f, 1.0f); // Strong border
		style.Colors[ImGuiCol_TableBorderLight] = dark;
		style.Colors[ImGuiCol_TableRowBg] = ImVec4(base.x * 0.8f, base.y * 0.8f, base.z * 0.8f, 1.0f);       // Table row background
		style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(base.x * 0.7f, base.y * 0.7f, base.z * 0.7f, 1.0f);    // Alternate table row background
		style.Colors[ImGuiCol_NavHighlight] = ImVec4(highlight.x * 1.1f, highlight.y * 1.1f, highlight.z * 1.1f, 1.0f);
		style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.7f, 0.85f, 1.0f, 0.8f);
		style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.75f);
		style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.75f);
	}

	IconParameters::IconParameters(std::string path, int width, int height)
		: path(std::move(path)), width(width), height(height)
	{}


	BackgroundImageParameters::BackgroundImageParameters(std::string path, ImageFitType fitType)
		: path(std::move(path)), fitType(fitType), width(0), height(0)
	{}

	UserInterfaceParameters::UserInterfaceParameters(WindowParameters windowParameters,
		FontParameters fontParameters,
		const StyleParameters& styleParameters,
		IconParameters iconParameters,
		BackgroundImageParameters bgImgParameters)
			: windowParameters(std::move(windowParameters)),
				fontParameters(std::move(fontParameters)),
				styleParameters(styleParameters),
				iconParameters(std::move(iconParameters)),
				backgroundImageParameters(std::move(bgImgParameters))
	{}

	void UserInterfaceParameters::save(const std::string& filename) const
	{
		windowParameters.save(filename);
	}
}


  
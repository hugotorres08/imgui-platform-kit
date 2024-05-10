
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <exception>
#include <filesystem>
#include <iostream>

#include "user_interface.h"
#include "template_window.h"
#include "log_window.h"

int main(int argc, char* argv[])
{
	try
	{
		std::cout << "Hello, World!" << std::endl;
		std::cout << "Current working directory: "
			<< std::filesystem::current_path()
			<< std::endl;

		using namespace imgui_kit;

		// You can use the following parameters to customize the user interface
		const WindowParameters windowParameters("Hello, World!");
		const FontParameters fontParameters("../../resources/fonts/Lexend-Light.ttf", 24);
		const StyleParameters styleParameters(ImVec4(0.2f, 0.2f, 0.2f, 0.8f), ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
		#ifdef _WIN32
		const IconParameters iconParameters("../../resources/icons/icon.ico");
		#elif __linux__
		const IconParameters iconParameters("../resources/icons/icon.png");
		#endif
		const BackgroundImageParameters backgroundImageParameters("../../resources/images/logo-bg.png",
			0.7);

		const UserInterfaceParameters parameters(windowParameters, 
			fontParameters, 
			styleParameters, 
			iconParameters, 
			backgroundImageParameters);
		UserInterface userInterface(parameters);

		// Or you can use the default parameters
		//UserInterface userInterface;

		userInterface.addWindow<TemplateWindow>();
		userInterface.addWindow<LogWindow>();
		//userInterface.addWindow<SomeOtherWindow>(arg1, arg2, arg3);

		LogWindow::addLog(colours::Green,"[DEBUG] Debug message.");
		LogWindow::addLog(colours::White,"[INFO] User  interface initialized.");
		LogWindow::addLog(colours::Yellow,"[WARNING] Warning message.");
		LogWindow::addLog(colours::Red,"[ERROR] Error message.");
		LogWindow::addLog(colours::Red,"[FATAL] Fatal error message.");

		userInterface.initialize();
		while(!userInterface.isShutdownRequested())
			userInterface.render();
		userInterface.shutdown();

		return 0;
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown exception" << std::endl;
		return 1;
	}
}

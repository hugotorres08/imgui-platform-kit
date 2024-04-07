
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <exception>
#include <filesystem>
#include <iostream>

#include "user_interface.h"

int main(int argc, char* argv[])
{
	try
	{
		std::cout << "Hello, World!" << std::endl;
		std::cout << "Current working directory: "
			<< std::filesystem::current_path()
			<< std::endl;

		using namespace imgui_kit::win32_directx12;

		const WindowParameters windowParameters(L"Hello, World!", 1280, 720);
		const FontParameters fontParameters("../../resources/fonts/Lexend-Light.ttf", 22);
		const StyleParameters styleParameters(ImVec4(0.2f, 0.2f, 0.2f, 0.8f));
		const IconParameters iconParameters("../../resources/icons/icon.ico");
		const BackgroundImageParameters backgroundImageParameters("../../resources/images/penrose-triangle-icon.png",
			0.7);

		const UserInterfaceParameters parameters(windowParameters, 
			fontParameters, 
			styleParameters, 
			iconParameters, 
			backgroundImageParameters);
		UserInterface userInterface(parameters);

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

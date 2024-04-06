
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <exception>
#include <iostream>

#include "user_interface.h"

int main(int argc, char* argv[])
{
	try
	{
		std::cout << "Hello, World!" << std::endl;

		using namespace imgui_kit::win32_directx12;

		const WindowParameters windowParameters(L"Hello, World!", 1280, 720);
		const FontParameters fontParameters("C:/Windows/Fonts/arial.ttf", 22);
		StyleParameters styleParameters;
		const UserInterfaceParameters parameters(windowParameters, fontParameters, styleParameters);
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

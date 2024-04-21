#pragma once

#include <string>

#include "imgui.h"

#if defined(_WIN32)
#include "imgui_impl_win32.h"
#include "imgui_impl_dx12.h"
#elif defined(__linux__)
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#endif

#include "implot.h"
#include "implot_internal.h"


namespace imgui_kit
{
	struct UserInterfaceWindowParameters
	{
		// This struct is intentionally left empty.
		// Derived structs are expected to define specific member variables
		// and functions relevant to their respective elements.
		UserInterfaceWindowParameters() = default;
		virtual ~UserInterfaceWindowParameters() = default;
	};

	class UserInterfaceWindow
	{
	public:
		UserInterfaceWindow() = default;
		virtual void render() = 0;
		virtual ~UserInterfaceWindow() = default;

		UserInterfaceWindow(const UserInterfaceWindow&) = delete;
		UserInterfaceWindow& operator=(const UserInterfaceWindow&) = delete;
		UserInterfaceWindow(UserInterfaceWindow&&) = delete;
		UserInterfaceWindow& operator=(UserInterfaceWindow&&) = delete;
	};
}
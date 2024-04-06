#include "user_interface_parameters.h"



namespace imgui_kit
{
		namespace win32_directx12
		{
			WindowParameters::WindowParameters(std::wstring title, int width, int height)
				: title(std::move(title))
				, width(width)
				, height(height)
			{
				if (width <= 0)
					throw std::invalid_argument("Width must be greater than 0.");
				if (height <= 0)
					throw std::invalid_argument("Height must be greater than 0.");
			}

			FontParameters::FontParameters(std::string path, int size)
				: path(std::move(path))
				, size(size)
			{
				if (size <= 0)
					throw std::invalid_argument("Size must be greater than 0.");
			}

			UserInterfaceParameters::UserInterfaceParameters(WindowParameters windowParameters, FontParameters fontParameters)
				: windowParameters(std::move(windowParameters)), fontParameters(std::move(fontParameters)), styleParameters()
			{
			}

			UserInterfaceParameters::UserInterfaceParameters(WindowParameters windowParameters, FontParameters fontParameters, const StyleParameters& styleParameters)
				: windowParameters(std::move(windowParameters))
			, fontParameters(std::move(fontParameters))
			, styleParameters(styleParameters)
			{
			}

	}
}

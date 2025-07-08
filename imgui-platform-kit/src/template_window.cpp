#include "template_window.h"

#include "themes.h"

namespace imgui_kit
{
	void TemplateWindow::render()
	{
		if (ImGui::Begin("Hello, world!"))
		{
			ImGui::Text("This is some useful text.");
			if(ImGui::Button("Button"))
				LogWindow::addLog(colours::White, "[INFO]    Informative message.");

		}
		ImGui::End();

		// Global Window Flags Controller
		static bool showFlagsWindow = true;

		if (ImGui::Begin("Global Window Flags Controller", &showFlagsWindow))
		{
			ImGui::Text("Control global window flags that affect 'My Window':");
			ImGui::Separator();

			ImGuiWindowFlags currentFlags = imgui_kit::getGlobalWindowFlags();

			// Basic flags with checkboxes
			bool noTitleBar = currentFlags & ImGuiWindowFlags_NoTitleBar;
			bool noResize = currentFlags & ImGuiWindowFlags_NoResize;
			bool noMove = currentFlags & ImGuiWindowFlags_NoMove;
			bool noScrollbar = currentFlags & ImGuiWindowFlags_NoScrollbar;
			bool noCollapse = currentFlags & ImGuiWindowFlags_NoCollapse;
			bool alwaysAutoResize = currentFlags & ImGuiWindowFlags_AlwaysAutoResize;
			bool noBackground = currentFlags & ImGuiWindowFlags_NoBackground;
			bool noSavedSettings = currentFlags & ImGuiWindowFlags_NoSavedSettings;
			bool horizontalScrollbar = currentFlags & ImGuiWindowFlags_HorizontalScrollbar;
			bool noFocusOnAppearing = currentFlags & ImGuiWindowFlags_NoFocusOnAppearing;
			bool noBringToFrontOnFocus = currentFlags & ImGuiWindowFlags_NoBringToFrontOnFocus;
			bool alwaysVerticalScrollbar = currentFlags & ImGuiWindowFlags_AlwaysVerticalScrollbar;
			bool alwaysHorizontalScrollbar = currentFlags & ImGuiWindowFlags_AlwaysHorizontalScrollbar;
			bool noNavInputs = currentFlags & ImGuiWindowFlags_NoNavInputs;
			bool noNavFocus = currentFlags & ImGuiWindowFlags_NoNavFocus;
			bool unsavedDocument = currentFlags & ImGuiWindowFlags_UnsavedDocument;

			if (ImGui::Checkbox("No Title Bar", &noTitleBar))
			{
				if (noTitleBar)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoTitleBar);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoTitleBar);
			}

			if (ImGui::Checkbox("No Resize", &noResize))
			{
				if (noResize)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoResize);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoResize);
			}

			if (ImGui::Checkbox("No Move", &noMove))
			{
				if (noMove)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoMove);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoMove);
			}

			if (ImGui::Checkbox("No Scrollbar", &noScrollbar))
			{
				if (noScrollbar)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoScrollbar);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoScrollbar);
			}

			if (ImGui::Checkbox("No Collapse", &noCollapse))
			{
				if (noCollapse)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoCollapse);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoCollapse);
			}

			if (ImGui::Checkbox("Always Auto Resize", &alwaysAutoResize))
			{
				if (alwaysAutoResize)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_AlwaysAutoResize);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_AlwaysAutoResize);
			}

			if (ImGui::Checkbox("No Background", &noBackground))
			{
				if (noBackground)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoBackground);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoBackground);
			}

			if (ImGui::Checkbox("No Saved Settings", &noSavedSettings))
			{
				if (noSavedSettings)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoSavedSettings);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoSavedSettings);
			}

			if (ImGui::Checkbox("Horizontal Scrollbar", &horizontalScrollbar))
			{
				if (horizontalScrollbar)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_HorizontalScrollbar);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_HorizontalScrollbar);
			}

			if (ImGui::Checkbox("No Focus On Appearing", &noFocusOnAppearing))
			{
				if (noFocusOnAppearing)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoFocusOnAppearing);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoFocusOnAppearing);
			}

			if (ImGui::Checkbox("No Bring To Front On Focus", &noBringToFrontOnFocus))
			{
				if (noBringToFrontOnFocus)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoBringToFrontOnFocus);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoBringToFrontOnFocus);
			}

			if (ImGui::Checkbox("Always Vertical Scrollbar", &alwaysVerticalScrollbar))
			{
				if (alwaysVerticalScrollbar)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_AlwaysVerticalScrollbar);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_AlwaysVerticalScrollbar);
			}

			if (ImGui::Checkbox("Always Horizontal Scrollbar", &alwaysHorizontalScrollbar))
			{
				if (alwaysHorizontalScrollbar)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_AlwaysHorizontalScrollbar);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_AlwaysHorizontalScrollbar);
			}

			if (ImGui::Checkbox("No Nav Inputs", &noNavInputs))
			{
				if (noNavInputs)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoNavInputs);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoNavInputs);
			}

			if (ImGui::Checkbox("No Nav Focus", &noNavFocus))
			{
				if (noNavFocus)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_NoNavFocus);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_NoNavFocus);
			}

			if (ImGui::Checkbox("Unsaved Document", &unsavedDocument))
			{
				if (unsavedDocument)
					imgui_kit::addGlobalWindowFlags(ImGuiWindowFlags_UnsavedDocument);
				else
					imgui_kit::removeGlobalWindowFlags(ImGuiWindowFlags_UnsavedDocument);
			}

			ImGui::Separator();

			if (ImGui::Button("Clear All Global Flags"))
			{
				imgui_kit::setGlobalWindowFlags(ImGuiWindowFlags_None);
			}
			ImGui::SameLine();
			if (ImGui::Button("Set Common Flags"))
			{
				imgui_kit::setGlobalWindowFlags(ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
			}

			ImGui::Text("Current global flags: 0x%08X", currentFlags);
		}
		ImGui::End();

		ImGuiWindowFlags flags = imgui_kit::getGlobalWindowFlags();

		// You can still add window-specific flags if needed:
		flags |= ImGuiWindowFlags_MenuBar; // This window needs a menu bar

		if (ImGui::Begin("My Window", nullptr, flags))
		{
			if (flags & ImGuiWindowFlags_MenuBar)
			{
				if (ImGui::BeginMenuBar())
				{
					if (ImGui::BeginMenu("File"))
					{
						ImGui::MenuItem("New");
						ImGui::MenuItem("Open");
						ImGui::MenuItem("Save");
						ImGui::EndMenu();
					}
					if (ImGui::BeginMenu("Edit"))
					{
						ImGui::MenuItem("Undo");
						ImGui::MenuItem("Redo");
						ImGui::EndMenu();
					}
					ImGui::EndMenuBar();
				}
			}

			ImGui::Text("This window uses global flags plus MenuBar!");
			ImGui::Text("Active flags: 0x%08X", flags);
			ImGui::Text("Global flags: 0x%08X", imgui_kit::getGlobalWindowFlags());

			// Add some content to test scrollbars
			for (int i = 0; i < 20; i++)
			{
				ImGui::Text("Line %d: This is some test content to demonstrate scrolling behavior.", i);
			}
		}
		ImGui::End();

		ImGui::ShowDemoWindow();
		ImGui::ShowStyleEditor();
		ImPlot::ShowDemoWindow();
		static bool show = true;
		imgui_kit::showImGuiKitThemeSelector(&show);
		}
}

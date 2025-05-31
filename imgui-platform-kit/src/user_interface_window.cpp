#include "user_interface_window.h"

namespace imgui_kit
{
    ImGuiWindowFlags g_globalWindowFlags = ImGuiWindowFlags_None;

    ImGuiWindowFlags getGlobalWindowFlags()
    {
        return g_globalWindowFlags;
    }

    void setGlobalWindowFlags(const ImGuiWindowFlags flags)
    {
        g_globalWindowFlags = flags;
    }

    void addGlobalWindowFlags(const ImGuiWindowFlags flags)
    {
        g_globalWindowFlags |= flags;
    }

    void removeGlobalWindowFlags(const ImGuiWindowFlags flags)
    {
        g_globalWindowFlags &= ~flags;
    }

}
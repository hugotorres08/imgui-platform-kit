
<img src="./imgui-platform-kit/resources/images/logo-bg.png" alt="logo" width="400" height="400">


imgui-platform-kit - Cross-platform toolkit for Dear ImGui.
===============================================


## Description
ImGui Platform Kit is a cross-platform toolkit designed to facilitate the development of user interfaces using Dear ImGui, integrated with DirectX 12 and ImPlot for Windows. This toolkit provides a comprehensive set of tools for creating customizable graphical interfaces, logging windows, and interactive plots, making it suitable for applications that require dynamic and visually appealing UI elements.

## Dependencies
- **C++20**: Compatible with modern C++ standards for optimal performance and functionality.
- **Dear ImGui**: Used for the base GUI components.
- **ImPlot**: Provides plotting capabilities within ImGui interfaces.
- **DirectX 12**: Required for rendering on Windows platforms.
- **STB Image**: For image loading and texture handling.
- **CMake 3.15 or higher**: For building and managing the project configurations.
- **VCPKG**: To manage C++ libraries on Windows, ensuring easy integration of ImGui and ImPlot.

## Functionalities
- **Dynamic Window Management**: Create and manipulate multiple window types with various properties.
- **Enhanced Logging**: Dedicated logging window with support for multiple log levels and colored text output.
- **Font and Style Customization**: Load and manage fonts and UI styles.
- **Background Image Handling**: Support for scalable background images in UI windows.
- **Screen Resolution Flexibility**: Automatically adjusts to the primary monitor's resolution if specific dimensions are not provided.
- **Plotting Integration**: Leverage ImPlot for integrated plotting capabilities within the ImGui interface.

## Getting started

1. Clone this repository to your local machine using Git.
2. Run the build.bat file. This will install all the necessary dependencies and build the project. Make sure you have VCPKG installed and the VCPKG_ROOT environment variable defined.
3. You can run the example executable to see the toolkit in action.

## Build and installing

Included in the project are ```build.bat``` and ```install.bat``` scripts to simplify the process of building and installing the ImGui Platform Kit:
- ```build.bat```: Compiles the project using predefined CMake commands.
- ```install.bat```: Installs the project to the specified location using CMake.

### Integration with Your Project
After running the ```install.bat``` script, the ImGui Platform Kit will be installed on your system. You can then integrate it with your own projects by modifying your CMake configuration to link against the installed ImGui Platform Kit library.

Here's an example snippet for a typical CMakeLists.txt that uses ImGui Platform Kit:

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyAwesomeApp)

# Find the ImGui Platform Kit package
find_package(imgui-platform-kit REQUIRED)

# Define your application's executable
add_executable(MyAwesomeApp main.cpp)

# Link against the ImGui Platform Kit
target_link_libraries(MyAwesomeApp PRIVATE imgui-platform-kit)
```

### How to Create a New Window

1. **Define Your Window Class**:
 ```cpp
 #include "base_window.h"

 class MyCustomWindow : public BaseWindow 
 {
 public:
     MyCustomWindow();
     void render() override;
 };
 ```
2. **Implement Your Window Class**
```cpp
MyCustomWindow::MyCustomWindow() 
{
    // Initialization code here
}

void MyCustomWindow::render() 
{
    if (ImGui::Begin("Custom Window")) 
        ImGui::Text("Hello, World!");
    ImGui::End();
}
 ```
3. **Instantiate and Use Your Window:**
Add your window to the UserInterface instance:
```cpp
UserInterface ui;
ui.addWindow<MyCustomWindow>();
```
This approach allows for easy extension and integration of new custom windows into the existing UI framework provided by ImGui Kit.
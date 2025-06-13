
<img src="./imgui-platform-kit/resources/images/logo-bg.png" alt="logo" length="400" width="400">


imgui-platform-kit - Cross-platform toolkit for Dear ImGui.
===============================================


## Description
**ImGui Platform Kit** is a cross-platform toolkit designed to facilitate the development of user interfaces using **Dear ImGui**, **ImPlot**, and **imgui-node-editor** integrated with DirectX 12 for Windows or integrated with GLFW, OpenGL3 for Linux. This toolkit provides a comprehensive set of tools for creating customizable graphical interfaces, logging windows, and interactive plots, making it suitable for applications that require dynamic and visually appealing UI elements.

## Common dependencies
- **C++20**: Compatible with modern C++ standards for optimal performance and functionality.
- **CMake 3.15 or higher**: For building and managing the project configurations.
- **VCPKG**: To manage C++ libraries on Windows, ensuring easy integration of ImGui and ImPlot.
- **Dear ImGui**: Used for the base GUI components (installed automatically when running ```build.bat``` on Windows or ```build.sh``` on Linux).
- **ImPlot**: Provides plotting capabilities within ImGui interfaces (installed automatically when running ```build.bat``` on Windows or ```build.sh``` on Linux).
- **imgui-node-editor**: Provides the capability of creating node-based graphs (installed automatically when running ```build.bat``` on Windows or ```build.sh``` on Linux).
- **STB Image**: For image loading and texture handling (already included in project).

## Windows specific dependencies
- **DirectX 12**: Required for rendering on Windows platforms.
  
## Linux specific dependencies
- **Open GL**: API for rendering 2D and 3D vector graphics.
- **GLFW**: Multi-platform library for OpenGL development on the desktop.

## Functionalities
- **Dynamic Window Management**: Create and manipulate multiple window types with various properties.
- **Enhanced Logging**: Dedicated logging window with support for multiple log levels and colored text output.
- **Font and Style Customization**: Load and manage fonts and UI styles.
- **Background Image Handling**: Support for scalable background images in UI windows.
- **Screen Resolution Flexibility**: Automatically adjusts to the primary monitor's resolution if specific dimensions are not provided.
- **Plotting Integration**: Leverage ImPlot for integrated plotting capabilities within the ImGui interface.
- **Node-based Graph Editing**: Implement node-based graphs using the imgui-node-editor library.

## Getting started

1. Clone this repository to your local machine using Git.
2. Run the build.bat file. This will install all the necessary dependencies and build the project. Make sure you have VCPKG installed and the VCPKG_ROOT environment variable defined.
3. You can run the example executable to see the toolkit in action.

## Build and installing

Included in the project are ```build.bat```, ```build.sh``` and ```install.bat```, ```install.sh``` scripts to simplify the process of building and installing the ImGui Platform Kit:
- ```build.bat```, ```build.sh```: Compiles the project using predefined CMake commands.
- ```install.bat```, ```install.sh```: Installs the project to the specified location using CMake.

**Note:**
In a Linux machine you might have to:
1. Create a build directory inside the project folder ```mkdir build```;
2. Set ```VCPKG_ROOT``` directory as an environment variable ```export VCPKG_ROOT=/opt/vcpkg```.
Before running the ```build.sh```.

### Integration with Your Project
After running the ```install.bat```, ```install.sh``` script, the ImGui Platform Kit will be installed on your system. You can then integrate it with your own projects by modifying your CMake configuration to link against the installed ImGui Platform Kit library.

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

## Dependencies that aren't installed automatically

### Installing CMake

```bash
sudo apt update
sudo apt install cmake

sudo apt install build-essential
```

### Installing vcpkg

https://lindevs.com/install-vcpkg-on-ubuntu

```bash
sudo apt update
sudo apt install -y zip unzip

sudo apt install -y build-essential pkg-config
wget -qO vcpkg.tar.gz https://github.com/microsoft/vcpkg/archive/master.tar.gz

sudo mkdir /opt/vcpkg
sudo tar xf vcpkg.tar.gz --strip-components=1 -C /opt/vcpkg

sudo /opt/vcpkg/bootstrap-vcpkg.sh
sudo ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg

vcpkg version
```

Add vpkg root to your environment variables. Open your .bashrc and add:

```bash
export VCPKG_ROOT=/opt/vcpkg
```

### Installing OpenGL

https://www.khronos.org/opengl/wiki/Getting_Started#Downloading_OpenGL

OpenGl should be installed by default if you have your graphics drivers installed.

Checking the version

```bash
sudo apt-get install mesa-utils
glxinfo | grep "OpenGL version"
```

### Installing GLFW

https://shnoh171.github.io/gpu%20and%20gpu%20programming/2019/08/26/installing-glfw-on-ubuntu.html

```bash
sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev
```

### Using g++ 13 on Ubuntu 22.04 for stuff like std::ranges

https://lindevs.com/install-g-on-ubuntu/

```bash
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt install -y g++-13
g++-13 --version # verify
```

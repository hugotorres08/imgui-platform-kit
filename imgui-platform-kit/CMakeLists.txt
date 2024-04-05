cmake_minimum_required(VERSION 3.15)

project(imgui-platform-kit
        DESCRIPTION "Cross-platform toolkit for Dear ImGui"
        LANGUAGES CXX
)

# Define library version
set(IMGUI_PLATFORM_KIT_VERSION_MAJOR 1 CACHE STRING "major version" FORCE)
set(IMGUI_PLATFORM_KIT_VERSION_MINOR 0 CACHE STRING "minor version" FORCE)
set(IMGUI_PLATFORM_KIT_VERSION ${IMGUI_PLATFORM_KIT_VERSION_MAJOR}.${IMGUI_PLATFORM_KIT_VERSION_MINOR} CACHE STRING "version" FORCE)

set(IMGUI_PLATFORM_KIT_LIB_PREFIX "release")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(IMGUI_PLATFORM_KIT_LIB_PREFIX "debug")
endif()

set(IMGUI_PLATFORM_KIT_INC_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include")
set(IMGUI_PLATFORM_KIT_RUNTIME_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin")
set(IMGUI_PLATFORM_KIT_LIBRARY_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/${IMGUI_PLATFORM_KIT_LIB_PREFIX}")
set(IMGUI_PLATFORM_KIT_ARCHIVE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/${IMGUI_PLATFORM_KIT_LIB_PREFIX}")
set(IMGUI_PLATFORM_KIT_FRAMEWORK_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin")
set(IMGUI_PLATFORM_KIT_CMAKE_CONFIG_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}")
set(IMGUI_PLATFORM_KIT_ADDITIONAL_FILES_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check whether VCPKG is set up in your system
if(NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR "ERROR: This project requires VCPKG.\n")
endif()

# Set VCPKG root directory
set(VCPKG_ROOT $ENV{VCPKG_ROOT})

# Include VCPKG toolchain
include(${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

# Set the project directory
set(PROJECT_DIR "${CMAKE_SOURCE_DIR}")
# Pass the PROJECT_DIR as a preprocessor definition
add_compile_definitions(PROJECT_DIR="${PROJECT_DIR}")

# Set the desired data output directory
set(OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/data")
# Pass the OUTPUT_DIRECTORY as a preprocessor definition
add_compile_definitions(OUTPUT_DIRECTORY="${OUTPUT_DIRECTORY}")

# Set header files
set(header 

)

# Set source files
set(src 

)

# Define library target
add_library(${CMAKE_PROJECT_NAME} 
    ${header}
    ${src}
)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> 
    $<INSTALL_INTERFACE:${IMGUI_PLATFORM_KIT_INC_INSTALL_DIR}> 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Setup imgui - win32 Directx12
find_package(imgui CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE imgui::imgui "d3d12.lib" "dxgi.lib" "d3dcompiler.lib")

# Setup implot
find_package(implot CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE implot::implot)

target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
    IMGUI_PLATFORM_KIT=1
    IMGUI_PLATFORM_KIT_VERSION_MAJOR=${IMGUI_PLATFORM_KIT_VERSION_MAJOR}
    IMGUI_PLATFORM_KIT_VERSION_MINOR=${IMGUI_PLATFORM_KIT_VERSION_MINOR}
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "${CMAKE_PROJECT_NAME}-${IMGUI_PLATFORM_KIT_VERSION}"
    POSITION_INDEPENDENT_CODE ON
)

install(TARGETS ${CMAKE_PROJECT_NAME} EXPORT ${CMAKE_PROJECT_NAME}Targets
    RUNTIME       DESTINATION ${IMGUI_PLATFORM_KIT_RUNTIME_INSTALL_DIR}
    LIBRARY       DESTINATION ${IMGUI_PLATFORM_KIT_LIBRARY_INSTALL_DIR}
    ARCHIVE       DESTINATION ${IMGUI_PLATFORM_KIT_ARCHIVE_INSTALL_DIR}
    FRAMEWORK     DESTINATION ${IMGUI_PLATFORM_KIT_FRAMEWORK_INSTALL_DIR}
)

include(CMakePackageConfigHelpers)
set(version_file "${CMAKE_CURRENT_BINARY_DIR}/cmake/${CMAKE_PROJECT_NAME}-config-version.cmake")
write_basic_package_version_file(${version_file}
    VERSION ${IMGUI_PLATFORM_KIT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION ${IMGUI_PLATFORM_KIT_CMAKE_CONFIG_INSTALL_DIR}
    FILE ${CMAKE_PROJECT_NAME}-config.cmake
)

# Add executable example project
set(EXE_PROJECT_EXAMPLE ${CMAKE_PROJECT_NAME}-example)
add_executable(${EXE_PROJECT_EXAMPLE} "examples/example.cpp")
target_include_directories(${EXE_PROJECT_EXAMPLE} PRIVATE include)
target_link_libraries(${EXE_PROJECT_EXAMPLE} PRIVATE imgui::imgui ${CMAKE_PROJECT_NAME})
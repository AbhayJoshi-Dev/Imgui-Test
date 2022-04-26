cmake_minimum_required(VERSION 3.21.2)

project(Imgui_Test)

find_package(OpenGL REQUIRED)

add_subdirectory(external/SDL)

include_directories(${CMAKE_SOURCE_DIR}/external/SDL/include/)

set(GLAD_SOURCE_FILES
  external/glad/src/glad.c)

set(GLAD_HEADER_FILES
  external/glad/include/glad/glad.h
  external/glad/include/KHR/khrplatform.h)

add_library(glad STATIC ${GLAD_SOURCE_FILES} ${GLAD_HEADER_FILES})
target_include_directories(glad PUBLIC external/glad/include)

set(IMGUI_SOURCE_FILES
  external/imgui/imgui.cpp
  external/imgui/imgui_demo.cpp
  external/imgui/imgui_draw.cpp
  external/imgui/imgui_impl_opengl3.cpp
  external/imgui/imgui_impl_sdl.cpp
  external/imgui/imgui_tables.cpp
  external/imgui/imgui_widgets.cpp)

set(IMGUI_HEADER_FILES
  external/imgui/imconfig.h
  external/imgui/imgui.h
  external/imgui/imgui_internal.h
  external/imgui/imstb_rectpack.h
  external/imgui/imstb_textedit.h
  external/imgui/imstb_truetype.h
  external/imgui/imgui_impl_opengl3.h
  external/imgui/imgui_impl_sdl.h
  external/imgui/imgui_impl_opengl3_loader.h)

add_library(imgui STATIC ${IMGUI_SOURCE_FILES} ${IMGUI_HEADER_FILES})
target_include_directories(imgui PUBLIC external/imgui/)


file(GLOB IMGUI_TEST_SOURCE_FILES *.cpp)
file(GLOB IMGUI_TEST_HEADER_FILES *.h)

add_executable(Imgui_Test ${IMGUI_TEST_SOURCE_FILES} ${IMGUI_TEST_HEADER_FILES})

target_link_libraries(Imgui_Test
        glad
        imgui
        SDL2
        SDL2main
        ${OPENGL_gl_LIBRARY}
        )

add_custom_command(TARGET Imgui_Test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${CMAKE_SOURCE_DIR}/build/external/SDL/Debug/SDL2d.dll"
                    "${CMAKE_SOURCE_DIR}/font.ttf"
                    $<TARGET_FILE_DIR:Imgui_Test>)
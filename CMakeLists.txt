cmake_minimum_required(VERSION 3.21.2)

project(Imgui_Test)

add_subdirectory(external/SDL)

include_directories(${CMAKE_SOURCE_DIR}/external/SDL/include/)

set(IMGUI_SOURCE_FILES
  external/imgui/imgui.cpp
  external/imgui/imgui_demo.cpp
  external/imgui/imgui_draw.cpp
  external/imgui/imgui_impl_sdlrenderer.cpp
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
  external/imgui/imgui_impl_sdlrenderer.h
  external/imgui/imgui_impl_sdl.h)

add_library(imgui STATIC ${IMGUI_SOURCE_FILES} ${IMGUI_HEADER_FILES})
target_include_directories(imgui PUBLIC external/imgui/)

add_executable(Imgui_Test main.cpp)

target_link_libraries(Imgui_Test
        imgui
        SDL2
        SDL2main
        )

add_custom_command(TARGET Imgui_Test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${CMAKE_SOURCE_DIR}/build/external/SDL/Debug/SDL2d.dll"
                    $<TARGET_FILE_DIR:Imgui_Test>)
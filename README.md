# Imgui-Test

An experiment for learning and building [imgui](https://github.com/ocornut/imgui) with [SDL2](https://github.com/libsdl-org/SDL) and [glad](https://github.com/Dav1dde/glad)

## Demo

![](https://i.imgur.com/Shf77Db.png)

## Build Instructions

- Requirements
  - Git
  - CMake
  - C++ Compiler

- Steps

    ```cmd
    # Clone this project along with submodules
    $ git clone --recursive https://github.com/AbhayJoshi-Dev/Imgui-Test

    # Go to project root
    $ cd Imgui-Test

    # Pull SDL as submodule (if you cloned without --recursive flag)
    $ git submodule update --init

    # Create a folder for build
    $ mkdir build

    # Go to build folder
    $ cd build

    # Generate project files
    $ cmake ..
    ```

- This will generate project files using default cmake generator for your platform. For example:

  - on `Windows` with `Visual Studio` installed, it will generate a `.sln`
  - on `Linux` with `make` installed, it will generate a `Makefile`
  - on `Mac` with `xcode` installed, it will generate a `.xcodeproj`

## Resources

Thanks to this article - https://decovar.dev/blog/2019/05/26/sdl-imgui/
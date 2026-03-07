cmake_minimum_required(VERSION 3.31.6)
project(JamGame VERSION 1.0.0)

find_package(OpenGL REQUIRED)

add_executable(JamGame
    src/main.cpp

    src/core/util.cpp
    src/core/util.hpp

    src/core/game.cpp
    src/core/game.hpp
    
    src/core/window.cpp
    src/core/window.hpp
    src/core/spriterenderer.cpp
    src/core/spriterenderer.hpp
    src/core/shader.cpp
    src/core/shader.hpp
    
    src/core/texture.cpp
    src/core/texture.hpp
    src/core/sprite.cpp
    src/core/sprite.hpp
    
    src/native/glglfw.h
    src/native/gl.c
    src/native/stb_image.h
    src/native/stb.cpp
)

target_include_directories(JamGame PRIVATE dependencies)
target_link_directories(JamGame PRIVATE lib)

target_link_libraries(JamGame
    glfw3
    OpenGL::GL
)
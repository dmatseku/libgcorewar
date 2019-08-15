cmake_minimum_required(VERSION 3.14)
project(gcorewar C)

set(CMAKE_C_STANDARD 99)

include_directories(include ../../libglstring/includes ../../libmatrix/includes
        ../../brew/Cellar/freetype/2.10.1/include/freetype2/ ../../brew/Cellar/glew/2.1.0/include/
        ../../brew/Cellar/glfw/3.3/include/)

#add_subdirectory(../../libmatrix ./cmake-libmatrix)

#add_subdirectory(../../libglstring ./cmake-libglstring)

#link_libraries(GLEW.2.1.0.dylib glfw.3.3.dylib m freetype matrix glstring)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon")

#link_directories(./cmake-build-debug ../../brew/Cellar/freetype/2.10.1/lib/ ../../brew/Cellar/glew/2.1.0/lib/
#        ../../brew/Cellar/glfw/3.3/lib/)

add_library(gcorewar STATIC include/libgcorewar.h init/corewar_visual_init.c other/other.c init/init_set_drawable_elems.c init/frame/create_frame_vao.c init/shaders/frame_shaders.c init/frame/create_frame_shader_program.c draw/draw.c)
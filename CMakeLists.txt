cmake_minimum_required(VERSION 3.14)
project(gcorewar C)

set(CMAKE_C_STANDARD 99)

#    include_directories(include  ../libmatrix/includes/ ../libglstring/includes)
    include_directories(include ../../libglstring/includes ../../libmatrix/includes
        ../../brew/Cellar/freetype/2.10.1/include/freetype2/ ../../brew/Cellar/glew/2.1.0/include/
        ../../brew/Cellar/glfw/3.3/include/)

#add_subdirectory(../../libmatrix ./cmake-libmatrix)

#add_subdirectory(../../libglstring ./cmake-libglstring)

#link_libraries(GLEW.2.1.0.dylib glfw.3.3.dylib m freetype matrix glstring)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon")

#link_directories(./cmake-build-debug ../../brew/Cellar/freetype/2.10.1/lib/ ../../brew/Cellar/glew/2.1.0/lib/
#        ../../brew/Cellar/glfw/3.3/lib/)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")

add_library(gcorewar STATIC init/corewar_visual_init.c other/other.c init/init_set_drawable_elems.c
        init/frame/create_frame_vao.c init/shaders/frame_shaders.c init/frame/create_frame_shader_program.c
        draw/draw.c init/str_step_counter/str_step_counter_draw_init.c
        init/str_champions/str_champions_create.c init/str_champions/str_champions_draw_init.c
        init/create_pictures/create_picture_carriage.c init/carriages/create_carriage_vao.c
        init/shaders/carriage_shaders.c draw/carriage_draw.c
        init/str_map/str_map_create.c other/other_2.c init/str_map/str_map_draw_function.c step/corewar_visual_step.c
        step/update_map.c draw/step_draw.c step/str_step_carriage.c init/carriages/create_carriage.c
        other/other_3.c draw/frame_draw.c
        init/static_string_animation_init/static_string_animation_init.c init/str_xlogins/str_xlogins_create.c
        init/lines/lines.c draw/lines_draw.c init/create_pictures/create_picture_x.c init/X/create_x_vao.c
        init/X/create_x.c init/shaders/x_shaders.c init/X/create_x_shader_program.c draw/x_draw.c t_carriage_list/carriage_list_update.c t_carriage_list/carriage_list_add.c t_carriage_list/carriage_list_del.c init/str_counters/str_counters_create.c step/step_x.c corewar_visual_destroy.c)
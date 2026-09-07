cmake_minimum_required(VERSION 3.20)

project(PA1_Computacion_Grafica)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        freeglut
        GIT_REPOSITORY https://github.com/freeglut/freeglut.git
        GIT_TAG v3.8.0
)

set(FREEGLUT_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(FREEGLUT_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(FREEGLUT_BUILD_STATIC_LIBS ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(freeglut)

add_executable(PA1_Computacion_Grafica
        main.cpp
)

target_include_directories(PA1_Computacion_Grafica
        PRIVATE
        ${freeglut_SOURCE_DIR}/include
)

target_link_libraries(PA1_Computacion_Grafica
        PRIVATE
        freeglut_static
        opengl32
        winmm
        gdi32
)

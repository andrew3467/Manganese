cmake_minimum_required(VERSION 3.27)
project(Rhenium)

set(CMAKE_CXX_STANDARD 23)

# SPDLog
include_directories(external/spdlog/include)
add_subdirectory(external/spdlog)

# GLFW
include_directories(external/glfw/include)
add_subdirectory(external/glfw)

#Tell glfw not to include OpenGL
add_compile_definitions(GLFW_INCLUDE_NONE)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# GLAD
include_directories(external/glad/include)
add_subdirectory(external/glad)


# GLM
include_directories(external/glm)
add_subdirectory(external/glm)




include_directories(src/Rhenium)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

add_library(Rhenium
        ${SRC}
        ${HEADERS}
)

target_precompile_headers(Rhenium
        PRIVATE
        src/rhpch.h
)

target_link_libraries(Rhenium
        PUBLIC
        glfw
        glad
        glm
)

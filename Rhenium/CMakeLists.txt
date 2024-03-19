cmake_minimum_required(VERSION 3.27)
project(Rhenium)

set(CMAKE_CXX_STANDARD 23)



include_directories(src/Rhenium)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

add_executable(Rhenium
        ${SRC}
        ${HEADERS}
)

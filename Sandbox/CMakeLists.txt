cmake_minimum_required(VERSION 3.27)
project(Manganese)

set(CMAKE_CXX_STANDARD 23)


include_directories(../Rhenium/src)
add_subdirectory(../Rhenium ../bin)


include_directories(src)


file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

add_executable(Manganese
    ${SRC}
    ${HEADERS}
)

target_link_libraries(Manganese
        PRIVATE
        Rhenium
)

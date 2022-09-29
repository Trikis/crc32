cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)


project(i_hate_crc32)

option(MultiThreading "MultiThreading" OFF)

set(SOURCE_LIB lib/console.cpp lib/main_func.h)
add_library(crc32 STATIC ${SOURCE_LIB})

if(MultiThreading)
    set(SOURCE_EXE main_threads.cpp)

    add_executable(i_hate_crc32_multithreading ${SOURCE_EXE})

    target_link_libraries(i_hate_crc32_multithreading crc32)
else()
    set(SOURCE_EXE main.cpp)

    add_executable(i_hate_crc32 ${SOURCE_EXE})

    target_link_libraries(i_hate_crc32 crc32)
endif()



add_subdirectory(tests)
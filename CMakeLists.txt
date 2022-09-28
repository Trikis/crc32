cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 17)


project(i_hate_crc32)

option(MultiThreading "MultiThreading" OFF)

set(SOURCE_LIB lib/console.cpp lib/main_func.cpp)
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



add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

add_executable(
    tests
    tests/crc32tests.cpp
)

target_include_directories(
    tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/lib"
)


target_link_libraries(
    tests PRIVATE
    gtest gtest_main 
)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(
            tests PRIVATE 
            /W4
    )
    if(MultiThreading)
        target_compile_options(
            i_hate_crc32_multithreading PRIVATE 
            /W4
        )
    else()
        target_compile_options(
            i_hate_crc32 PRIVATE 
            /W4
        )
    endif()

else()
    target_compile_options(
        tests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(MultiThreading)
        target_compile_options(
            i_hate_crc32_multithreading PRIVATE 
            -Wall -Wextra -pedantic -Werror
        )
    else()
        target_compile_options(
            i_hate_crc32 PRIVATE 
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()
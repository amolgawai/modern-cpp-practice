cmake_minimum_required(VERSION 3.23)
target_sources(IntroApp PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_runner.cpp
    )
target_include_directories(IntroApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory("bk_lrncppbyex")
add_subdirectory("utils")
cmake_minimum_required(VERSION 3.23)
target_sources(IntroApp PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/bk_lrncppbyex_provider.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pascles_triangle.cpp
    )
target_include_directories(IntroApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
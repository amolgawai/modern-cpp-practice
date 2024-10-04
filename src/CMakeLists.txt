cmake_minimum_required(VERSION 3.23)
target_sources(IntroApp PRIVATE "main.cpp")
target_include_directories(IntroApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory("bk_lrn_cpp_by_exmpl")
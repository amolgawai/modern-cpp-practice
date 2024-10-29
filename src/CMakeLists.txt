cmake_minimum_required(VERSION 3.23)
target_sources(IntroApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_runner.cpp
    )
if(ENABLE_TESTING)
    target_include_directories(main_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_sources(main_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main_test.cpp
    )
endif()
target_include_directories(IntroApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory("bk_lrncppbyex")
add_subdirectory("utils")

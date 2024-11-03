cmake_minimum_required(VERSION 3.23)
target_sources(run_examples PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/bk_lrncppbyex_provider.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pascles_triangle.cpp
    )
target_include_directories(run_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(ENABLE_TESTING)
    target_sources(run_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/pascles_triangle.cpp
    )
endif()

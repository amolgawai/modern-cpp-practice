cmake_minimum_required(VERSION 3.23)

# ---- Project ----

# Note: update this to your new project's name and version
project(
    ModernCPPPractice
    VERSION 1.0
    DESCRIPTION "Practicing Modern C++"
    LANGUAGES CXX
)

include(CMakePrintHelpers)
# Options: Things you can set via commandline options to cmake (e.g. -DENABLE_LTO=[ON|OFF])
option(ENABLE_WARNINGS_SETTINGS "Allow target_set_warnings to add flags and defines.
                                 Set this to OFF if you want to provide your own warning parameters." ON
)
option(ENABLE_LTO "Enable link time optimization" ON)
option(ENABLE_CODE_COVERAGE "Enable test coverage" OFF)
# option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code. Tests
# in tests/*.cpp will still be enabled." ON)

# Include stuff. No change needed.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(ConfigSafeGuards)
include(Colors)
include(LTO)
include(Misc)
include(Warnings)
include(CPM)
include(tools)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app Note this needs to be done in the main CMakeLists since it calls
    # enable_testing, which must be in the main CMakeLists.
    include(CTest)
    if(ENABLE_CODE_COVERAGE)
        # Adds a 'coverage' target.
        include(CodeCoverage)
    endif()
    # Docs only available if this is the main app
    include(Documentation)
endif()

# Check for LTO support.
find_lto(CXX)

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info

CPMAddPackage(
    NAME fmt
    GIT_TAG 8.1.1
    GITHUB_REPOSITORY fmtlib/fmt
    OPTIONS "FMT_INSTALL YES" # create an installable target
)
CPMAddPackage("gh:onqtam/doctest@2.4.9")
# CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")
CPMAddPackage(
    NAME Format.cmake
    VERSION 1.7.3
    GITHUB_REPOSITORY TheLartians/Format.cmake
    OPTIONS # set to yes skip cmake formatting
            "FORMAT_SKIP_CMAKE NO"
            # path to exclude (optional, supports regular expressions)
            "CMAKE_FORMAT_EXCLUDE (cmake/.*|_deps/.*|cpm-package-lock\.cmake)"
)
# add_subdirectory(libs)

CPMAddPackage(
    GITHUB_REPOSITORY jarro2783/cxxopts
    VERSION 3.0.0
    OPTIONS "CXXOPTS_BUILD_EXAMPLES NO" "CXXOPTS_BUILD_TESTS NO" "CXXOPTS_ENABLE_INSTALL YES"
)

CPMAddPackage("gh:eliaskosunen/scnlib@1.1.2")


add_executable(IntroApp)
add_subdirectory("src")
target_include_directories(IntroApp PRIVATE "${PROJECT_SOURCE_DIR}")

target_compile_features(IntroApp PRIVATE cxx_std_20)
set_target_properties(IntroApp PROPERTIES OUTPUT_NAME "IntroApp")
target_set_warnings(
    IntroApp
    ENABLE
    ALL
    AS_ERROR
    ALL
    DISABLE
    Annoying
) # Set warnings (if needed).

target_link_libraries(IntroApp cxxopts::cxxopts scn::scn fmt::fmt)

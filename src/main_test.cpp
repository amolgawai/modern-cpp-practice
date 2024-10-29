// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include <doctest/doctest.h>

// Do not compile the main class object with the tests to speed up compilation!
// https://github.com/doctest/doctest/issues/53#issuecomment-315173323
// #define DOCTEST_CONFIG_NO_POSIX_SIGNALS  // catch segfault on gdb
#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

// Call ./main_test -tc="01*" -sc="01*" in a terminal to only run the firts test and first subcase
// https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
int main(int argc, char** argv)
{
    doctest::Context context;
    context.applyCommandLine(argc, argv);

    int res = context.run();
    // some teardown?

    if(context.shouldExit()) {
        return res;
    }
    // the application code if the tests were not run
    return res;
}

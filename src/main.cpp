#include <cxxopts.hpp>                             // for Options, OptionAdder
#include <exception>                               // for exception
#include <memory>                                  // for unique_ptr
#include <string>                                  // for basic_string, string

// #include "app_defs.hpp"
#include "bk_lrncppbyex_provider.hpp"  // for get_examples
#include "example.hpp"                         // for Example
#include "example_runner.hpp"
#include "cli_io.hpp"

auto process_options(int argc, char** argv) -> int {
    cxxopts::Options options(*argv, "A program to welcome the world!");

    options.add_options()("h,help", "Show help")("v,version", "Print the current version number");
    try {
        auto result{options.parse(argc, argv)};

        if (result["help"].as<bool>()) {
            std::cout << options.help() << std::endl;
            return 0;
        }

        if (result["version"].as<bool>()) {
            std::cout << "1.0.0" << std::endl;
            return 0;
        }
    } catch (const std::exception& e) {
        cli_io::show_msg_error("Error parsing options: " + std::string(e.what()));
        return 1;
    }

    return 1;
}

auto main(int argc, char** argv) -> int {
    auto res = process_options(argc, argv);
    if (res == 0) {
        return 0;
    }
    cli_io::show_msg_title("Hello Modern C++");

    auto bkLrnCPPBYExProvider = bk_LrnCPPByEx::LrnCPPByExProvider{};
    auto examples1 = bkLrnCPPBYExProvider.provideExamples();
    auto exampleRunner = cpp_practice::ExampleRunner{};
    exampleRunner.runExamples(examples1);

    return 0;
}

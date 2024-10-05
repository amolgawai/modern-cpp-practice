#include <cxxopts.hpp>  // for Options, OptionAdder, OptionValue
#include <exception>    // for exception
#include <iostream>     // for basic_ostream, endl, operator<<
#include <string>       // for basic_string, char_traits, ope...

#include "bk_lrncppbyex_provider.hpp"  // for LrnCPPByExProvider
#include "cli_io.hpp"                  // for show_msg_error, show_msg_title
#include "example_runner.hpp"          // for ExampleRunner

auto process_options(int argc, char** argv) -> int {
    cxxopts::Options options(*argv, "A program to welcome the world!");

    options.add_options()("h,help", "Show help")("v,version", "Print the current version number");
    try {
        auto result{options.parse(argc, argv)};

        if (result["help"].as<bool>()) {
            std::cout << options.help() << "\n";
            return 0;
        }

        if (result["version"].as<bool>()) {
            std::cout << "1.0.0" << "\n";
            return 0;
        }
    } catch (const std::exception& e) {
        cli_io::show_msg_error("Error parsing options: " + std::string(e.what()));
        return 1;
    }

    return 1;
}

auto run_examples() {
    cli_io::show_msg_title("Hello Modern C++");

    bk_LrnCPPByEx::LrnCPPByExProvider bkLrnCPPBYExProvider = bk_LrnCPPByEx::LrnCPPByExProvider{};
    auto examples1 = bkLrnCPPBYExProvider.provideExamples();
    auto exampleRunner = cpp_practice::ExampleRunner{};
    exampleRunner.runExamples(examples1);
}

auto main(int argc, char** argv) -> int {
    try {
        auto res = process_options(argc, argv);
        if (res == 0) {
            return 0;
        }

        run_examples();

    } catch (const std::exception& ex) {
        std::cerr << ex.what() << "\n";
        return -1;
    }
    return 0;
}

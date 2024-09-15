#include <cxxopts.hpp>
#include <iostream>

#include "bk_lrn_cpp_by_exmpl/example_runner.hpp"
#include "example_cls.hpp"

namespace cpp_practice {
    class DemoExample : public Example {
    public:
        auto name() const -> std::string override { return std::string{"demo"}; };
        auto description() const -> std::string override { return std::string{"A demo example"}; }
        void run() const override { std::cout << "Demo is running now ...\n Finished\n"; };
        ~DemoExample() override = default;
    };
}  // namespace cpp_practice

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
        std::cerr << "Error parsing options: " << e.what() << std::endl;
        return 1;
    }

    return 1;
}

auto main(int argc, char** argv) -> int {
    auto res = process_options(argc, argv);
    if (res == 0) {
        return 0;
    }
    std::cout << "Hello Modern C++" << std::endl;

    auto demo1 = cpp_practice::DemoExample{};
    std::cout << "running - " << demo1.name() << "\n" << demo1.description() << "\n";
    demo1.run();

    auto examples1 = lrn_cpp_by_exmpl::get_examples();
    for (const auto& example : examples1) {
        std::cout << "running - " << example->name() << "\n" << example->description() << "\n";
        example->run();
    }

    return 0;
}

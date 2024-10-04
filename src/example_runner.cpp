#include <iostream>

#include "example_runner.hpp"
#include "app_defs.hpp"

namespace cpp_practice {
auto ExampleRunner::runExamples(const ExamplePtrContainer& examples) -> void {

    for (const auto& example : examples) {
        std::cout << "running - " << example->name() << "\n" << example->description() << "\n";
        example->run();
    }
};
}
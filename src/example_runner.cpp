#include "example_runner.hpp"
#include "app_defs.hpp"
#include "cli_io.hpp"

namespace cpp_practice {
auto ExampleRunner::runExamples(const ExamplePtrContainer& examples) -> void {

    for (const auto& example : examples) {
        cli_io::show_msg_subtitle("Running - " + example->name() + "\n" + example->description());
        example->run();
    }
};
}
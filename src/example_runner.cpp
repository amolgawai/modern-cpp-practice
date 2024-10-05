#include "example_runner.hpp"
#include <memory>        // for allocator, unique_ptr
#include <string>        // for char_traits, operator+, basic_string
#include "app_defs.hpp"  // for ExamplePtrContainer
#include "cli_io.hpp"    // for show_msg_subtitle
#include "example.hpp"   // for Example

namespace cpp_practice {
auto ExampleRunner::runExamples(const ExamplePtrContainer& examples) -> void {

    for (const auto& example : examples) {
        cli_io::show_msg_subtitle("Running - " + example->name() + "\n" + example->description());
        example->run();
    }
};
}
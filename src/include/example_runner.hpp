#pragma once

#include "app_defs.hpp"

namespace cpp_practice {

    class ExampleRunner {
    public:
        static auto runExamples(const ExamplePtrContainer& examples) -> void;
    };
}  // namespace cpp_practice

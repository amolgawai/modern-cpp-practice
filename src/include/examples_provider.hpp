#pragma once

#include "app_defs.hpp"

namespace cpp_practice {
    class ExamplesProvider {
    public:
        ExamplesProvider() = default;
        ExamplesProvider(const ExamplesProvider &) = default;
        ExamplesProvider(ExamplesProvider &&) = delete;
        ExamplesProvider &operator=(const ExamplesProvider &) = default;
        ExamplesProvider &operator=(ExamplesProvider &&) = delete;
        virtual ~ExamplesProvider() = default;
        virtual auto provideExamples() -> ExamplePtrContainer = 0;
    };
}  // namespace cpp_practice
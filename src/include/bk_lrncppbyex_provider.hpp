#pragma once

#include "app_defs.hpp"
#include "examples_provider.hpp"

namespace bk_LrnCPPByEx {
    class LrnCPPByExProvider : public cpp_practice::ExamplesProvider {
        public:
            auto provideExamples() -> ExamplePtrContainer override;
    };
}
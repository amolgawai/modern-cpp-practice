#pragma once

#include "app_defs.hpp"

namespace cpp_practice {
class ExamplesProvider {
  public:
    virtual auto provideExamples() -> ExamplePtrContainer = 0;
};
}
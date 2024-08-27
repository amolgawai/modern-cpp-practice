#pragma once

#include <memory>
#include <vector>

#include "../example_cls.hpp"

namespace lrn_cpp_by_exmpl {
    auto get_examples() -> std::vector<std::unique_ptr<cpp_practice::Example>>;
}
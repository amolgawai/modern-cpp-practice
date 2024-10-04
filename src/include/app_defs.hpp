#pragma once
#include <vector>
#include <memory>

#include "example.hpp"

using ExamplePtrContainer = std::vector<std::unique_ptr<cpp_practice::Example>>;
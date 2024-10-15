#include "bk_lrncppbyex_provider.hpp"  // for LrnCPPByExProvider

#include <iostream>  // for basic_ostream, operator<<, cout
#include <memory>    // for unique_ptr, make_unique
#include <string>    // for basic_string, string

#include "app_defs.hpp"          // for ExamplePtrContainer
#include "example.hpp"           // for Example
#include "pascles_triangle.hpp"  // for PasclesTriangle

namespace bk_LrnCPPByEx {

    class Demo : public cpp_practice::Example {
    public:
        Demo() = default;
        Demo(const Demo &) = delete;
        Demo &operator=(const Demo &) = delete;
        Demo(Demo &&) = default;
        Demo &operator=(Demo &&) = default;
        [[nodiscard]] auto name() const -> std::string override { return std::string{"Example 1"}; };
        [[nodiscard]] auto description() const -> std::string override { return std::string{"A demo example"}; }
        void run() const override { std::cout << "Demo is running now ...\n Finished\n"; };
        ~Demo() override = default;
    };

    auto LrnCPPByExProvider::provideExamples() -> ExamplePtrContainer {
        auto examples = ExamplePtrContainer{};
        examples.emplace_back(std::make_unique<Demo>());
        examples.emplace_back(std::make_unique<PasclesTriangle>());
        return examples;
    }
}  // namespace bk_LrnCPPByEx
#include <iostream>
#include <memory>
#include <vector>

#include "app_defs.hpp"
#include "example.hpp"
#include "pascles_triangle.hpp"
#include "bk_lrncppbyex_provider.hpp"

namespace bk_LrnCPPByEx {

    class Demo : public cpp_practice::Example {
    public:
        auto name() const -> std::string override { return std::string{"Example 1"}; };
        auto description() const -> std::string override { return std::string{"A demo example"}; }
        void run() const override { std::cout << "Demo is running now ...\n Finished\n"; };
        ~Demo() override = default;
    };

    auto LrnCPPByExProvider::provideExamples() -> ExamplePtrContainer {
        auto examples = ExamplePtrContainer{};
        examples.emplace_back(std::make_unique<Demo>());
        examples.emplace_back(std::make_unique<PasclesTriangle>());
        return examples;
    }
}  // namespace lrn_cpp_by_exmpl
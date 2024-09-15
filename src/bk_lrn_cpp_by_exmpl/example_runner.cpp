#include "example_runner.hpp"

#include <iostream>
#include <memory>
#include <vector>

#include "example_cls.hpp"

namespace lrn_cpp_by_exmpl {

    class Demo : public cpp_practice::Example {
    public:
        auto name() const -> std::string override { return std::string{"Example 1"}; };
        auto description() const -> std::string override { return std::string{"A demo example"}; }
        void run() const override { std::cout << "Demo is running now ...\n Finished\n"; };
        ~Demo() override = default;
    };

    auto get_examples() -> std::vector<std::unique_ptr<cpp_practice::Example>> {
        auto examples = std::vector<std::unique_ptr<cpp_practice::Example>>{};
        examples.push_back(std::make_unique<Demo>());
        return examples;
    }
}  // namespace lrn_cpp_by_exmpl
#pragma once

#include <string>

namespace cpp_practice {

    class Example {
    public:
        Example() = default;
        Example(const Example &) = delete;
        Example(Example &&) = default;
        Example &operator=(const Example &) = delete;
        Example &operator=(Example &&) = default;
        [[nodiscard]] virtual auto name() const -> std::string = 0;
        [[nodiscard]] virtual auto description() const -> std::string = 0;
        virtual void run() const = 0;
        virtual ~Example() = default;
    };
}  // namespace cpp_practice

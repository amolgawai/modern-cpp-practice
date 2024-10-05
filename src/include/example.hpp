#pragma once

#include <string>

namespace cpp_practice {

    class Example {
    public:
        Example() = default;
        [[nodiscard]] Example(const Example &) = default;
        Example(Example &&) = delete;
        Example &operator=(const Example &) = default;
        Example &operator=(Example &&) = delete;
        [[nodiscard]] virtual auto name() const -> std::string = 0;
        [[nodiscard]] virtual auto description() const -> std::string = 0;
        virtual void run() const = 0;
        virtual ~Example()= default;
    };
}  // namespace cpp_practice

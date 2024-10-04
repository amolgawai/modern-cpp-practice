#pragma once

#include <string>

namespace cpp_practice {

    class Example {
    public:
        virtual auto name() const -> std::string = 0;
        virtual auto description() const -> std::string = 0;
        virtual void run() const = 0;
        virtual ~Example(){};
    };
}  // namespace cpp_practice

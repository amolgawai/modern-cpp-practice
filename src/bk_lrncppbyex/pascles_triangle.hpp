#pragma once

#include <string>

#include "example.hpp"

namespace bk_LrnCPPByEx {
    class PasclesTriangle : public cpp_practice::Example {
        public:
        auto name() const -> std::string override { return std::string{"Pascales Triangle"}; };
        auto description() const -> std::string override { return std::string{"Constructs Pascles Triangle"}; }
        void run() const override;
        ~PasclesTriangle() override = default;
    };
}
#pragma once

#include <string>

#include "example.hpp"

namespace bk_LrnCPPByEx {
    class PasclesTriangle : public cpp_practice::Example {
        public:
            PasclesTriangle() = default;
            PasclesTriangle(const PasclesTriangle &) = default;
            PasclesTriangle(PasclesTriangle &&) = delete;
            PasclesTriangle &operator=(const PasclesTriangle &) = default;
            PasclesTriangle &operator=(PasclesTriangle &&) = delete;
            [[nodiscard]] auto name() const -> std::string override { return std::string{"Pascales Triangle"}; };
            [[nodiscard]] auto description() const -> std::string override { return std::string{"Constructs Pascles Triangle"}; }
            void run() const override;
            ~PasclesTriangle() override = default;
    };
}
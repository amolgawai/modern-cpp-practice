#pragma once
#include <string>

#include "example.hpp"

namespace bk_LrnCPPByEx {
    class PasclesTriangle : public cpp_practice::Example {
    public:
        PasclesTriangle() = default;
        PasclesTriangle(const PasclesTriangle &) = delete;
        PasclesTriangle(PasclesTriangle &&) = default;
        PasclesTriangle &operator=(const PasclesTriangle &) = delete;
        PasclesTriangle &operator=(PasclesTriangle &&) = default;
        [[nodiscard]] auto constexpr name() const -> std::string override { return std::string{"Pascales Triangle"}; };
        [[nodiscard]] auto constexpr description() const -> std::string override {
            return std::string{"Constructs Pascles Triangle"};
        }
        void run() const override;
        ~PasclesTriangle() override = default;
    };
}  // namespace bk_LrnCPPByEx

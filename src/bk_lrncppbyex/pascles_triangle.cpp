#include "pascles_triangle.hpp"

#include <cstddef>
#include <vector>

#include "cli_io.hpp"

namespace bk_LrnCPPByEx {
    using intVec = std::vector<int>;
    auto get_next_row(const intVec& prev_row) -> intVec {
        intVec next_row{1};
        for (size_t index = 0; index + 1 < prev_row.size(); ++index) {
            next_row.emplace_back(prev_row[index] + prev_row[index + 1]);
        }
        next_row.emplace_back(1);
        return next_row;
    }

    auto generate_triangles(int numRows) -> std::vector<intVec> {
        std::vector<intVec> triangles{{1}};
        for (int index = 1; index < numRows; ++index) {
            triangles.emplace_back(get_next_row(triangles.back()));
        }
        return triangles;
    }

    void show_triangles(const std::vector<intVec>& pascles_triangle) {
        size_t last_row_size = pascles_triangle.back().size();
        std::string spaces(last_row_size * 3, ' ');
        for (const auto& a_row : pascles_triangle) {
            cli_io::show_msg_info("{}", spaces);
            size_t spaces_size = spaces.size();
            if (spaces_size > 3) {
                spaces.resize(spaces_size - 3);
            }
            for (const auto& element : a_row) {
                // cli_io::show_msg_info("{:^{}}", element, 6);
                cli_io::show_msg_info("{:^6}", element);
            }
            cli_io::show_msg_info("\n");
        }
    }
    void PasclesTriangle::run() const {
        cli_io::show_msg_info("Running Pascales Triangle Example\n");
        const auto numRows = cli_io::get_single_value<int>("How many rows of Pascles Triangle you want?");
        cli_io::show_msg_info("Generating Pascles Triangle for {} rows\n", numRows);
        auto pascles_triangle = generate_triangles(numRows);
        show_triangles(pascles_triangle);
    };
}  // namespace bk_LrnCPPByEx

#include <doctest/doctest.h>

TEST_CASE("Pascles Triangle Tests") {
    constexpr int num_rows = 10;
    auto test_vec = bk_LrnCPPByEx::generate_triangles(num_rows);
    SUBCASE("01.") { CHECK(test_vec.size() == 10); }
    SUBCASE("02.") {
        [[maybe_unused]]size_t row_size = 1;
        for ([[maybe_unused]] const auto& row : test_vec) {
            CHECK(row.front() == 1);
            CHECK(row.back() == 1);
            CHECK(row.size() == row_size++);
        }
    }
}

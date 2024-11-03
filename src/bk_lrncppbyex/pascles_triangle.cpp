#include "pascles_triangle.hpp"

#include <cstddef>
#include <ranges>
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

    void show_triangles(const std::vector<intVec>& pascles_triangle, bool show_sierpinsky = false) {
        size_t last_row_size = pascles_triangle.back().size();
        size_t spacer{3};
        if (show_sierpinsky) {
            spacer = 1;
        }
        std::string spaces(last_row_size * spacer, ' ');
        for (const auto& a_row : pascles_triangle) {
            cli_io::show_msg_info("{}", spaces);
            size_t spaces_size = spaces.size();
            if (spaces_size > spacer) {
                spaces.resize(spaces_size - spacer);
            }
            if (show_sierpinsky) {
                auto odd_symbol_row = a_row | std::views::transform([](int x) { return (x % 2) != 0 ? '*' : ' '; });
                for (const auto& element : odd_symbol_row) {
                    cli_io::show_msg_info("{} ", element);
                }
            } else {
                for (const auto& element : a_row) {
                    cli_io::show_msg_info("{:^6}", element);
                }
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
        cli_io::show_msg_info("Sierpinsky Triangle of the Pascale's traingle is \n");
        show_triangles(pascles_triangle, true);
    };
}  // namespace bk_LrnCPPByEx

// Tests for the core triangle generation algo

#include <doctest/doctest.h>

#include <numeric>

TEST_CASE("Pascles Triangle Tests") {
    constexpr int num_rows = 10;
    auto test_vec = bk_LrnCPPByEx::generate_triangles(num_rows);
    SUBCASE("Size Check") { CHECK(test_vec.size() == 10); }
    SUBCASE("Properties Check") {
        [[maybe_unused]] size_t row_size = 1;
        [[maybe_unused]] int expected_row_total = 1;
        for ([[maybe_unused]] const auto& row : test_vec) {
            SUBCASE("Front and back element is 1") {
                CHECK(row.front() == 1);
                CHECK(row.back() == 1);
            }
            SUBCASE("row size increases by 1") { CHECK(row.size() == row_size++); }
            SUBCASE("sum of a row increases in power of 2") {
                CHECK(std::accumulate(row.begin(), row.end(), 0) == expected_row_total);
                expected_row_total *= 2;
            }
            SUBCASE("row has symmetrical numbers") {
                [[maybe_unused]] auto front = row | std::views::take(row.size() / 2);
                [[maybe_unused]] auto back = row | std::views::reverse | std::views::take(row.size() / 2);
                CHECK(std::ranges::equal(front, back));
            }
        }
    }
}

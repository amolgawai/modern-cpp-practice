#include "pascles_triangle.hpp"

#include <cstddef>
#include <iostream>
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

    void PasclesTriangle::run() const {
        cli_io::show_msg_info("Running Pascales Triangle Example\n");
        const auto numRows = cli_io::get_single_value<int>("How many rows of Pascles Triangle you want?");
        cli_io::show_msg_info("Generating Pascles Triangle for {} rows\n", numRows);
        auto pascles_triangle = generate_triangles(numRows);
        for (const auto& a_row : pascles_triangle) {
            for (const auto& element : a_row) {
                cli_io::show_msg_info("{} ", element);
            }
            std::cout << "\n";
        }
    };
}  // namespace bk_LrnCPPByEx
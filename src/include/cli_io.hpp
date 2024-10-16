#pragma once
// NOLINTBEGIN
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
// #include <scn/scan.h>

#include <iostream>  // IWYU pragma: keep
#include <sstream>   // IWYU pragma: keep
#include <string>    // for string, basic_string
// #include <vector>    // for vector

// stringstream can't handle uint_8, see following
// https://stackoverflow.com/questions/54627170/read-uint8-t-from-stdstingstream-as-a-numeric-type

namespace cli_io {

    // show messages to user
    void show_msg_title(const std::string_view msg);
    void show_msg_subtitle(const std::string_view msg);
    void show_msg_error(const std::string_view msg);
    template <typename... T> void show_msg_info(fmt::format_string<T...> format, T &&...args) {
        fmt::print(format, args...);
    };

    // Get input from user
    // template <typename NUM_TYP> std::vector<NUM_TYP> get_numbers(const std::string &msg) {
    //     fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic, "{}\n", msg);

    //     std::vector<NUM_TYP> input_nums;
    //     auto result = scn::scan_list_ex(scn::cstdin(), input_nums, scn::list_until('\n'));
    //     if (!result) {
    //         show_msg_error("Error occured during reading");
    //     }
    //     return input_nums;
    // };

    // Get a single value from user
    template <typename RET_TYP> auto get_single_value(const std::string &msg) {
        fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic, "{}\n", msg);
        RET_TYP return_value;
        std::cin >> return_value;
        return return_value;
        // const auto result = scn::input<RET_TYP>("{}");

        // if (!result) {
        //     show_msg_error("Error occured during reading");
        //     return RET_TYP{};
        // }
        // return result->value();
    };

}  // namespace cli_io

// NOLINTEND
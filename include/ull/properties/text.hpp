
/// \file text.hpp
/// Contains definition of the text property.

#pragma once

#include "../basic_property.hpp"
#include <string>


namespace ull {


/// Text property
template <typename Char>
struct text: public basic_property<std::basic_string<Char>> {
    text(const Char * str):
        basic_property<std::basic_string<Char>>{str} {}

    text(const std::basic_string<Char> & str):
        basic_property<std::basic_string<Char>>{str} {}

    text(std::basic_string<Char> && str):
        basic_property<std::basic_string<Char>>{std::move(str)} {}

    text(std::basic_string_view<Char> str):
        basic_property<std::basic_string<Char>>{std::move(str)} {}
};


}

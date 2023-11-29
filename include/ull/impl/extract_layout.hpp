
/// \file extract_layout.hpp
/// Contains definition of the extract_layout function and related types.

#pragma once

#include <tuple>


namespace ull {


template <typename Element>
auto extract_layout_single(Element && e) {
    if constexpr (std::derived_from<Element, layout_base>) {
        return std::tuple{std::move(e)};
    } else {
        return std::tuple{};
    }
}


/// Extracts layout object from UI elements
template <typename  ... Elements>
auto extract_layout(Elements && ... elements) {
    auto layouts = std::tuple_cat(extract_layout_single(std::move(elements))...);
    static_assert(std::tuple_size_v<decltype(layouts)> <= 1 && "widget has multiple layouts");

    if constexpr (std::tuple_size_v<decltype(layouts)> == 1) {
        return std::get<0>(std::move(layouts));
    } else {
        return std::tuple{};
    }
}


/// Type of layout for widget for specified children elements
template <typename ... Elements>
using widget_layout_t = decltype(extract_layout(std::declval<Elements>()...));


}


/// \file extract_widgets.hpp
/// Contains definition of the extract_widgets function and related types.

#pragma once

#include "../layout_base.hpp"
#include "../widget_base.hpp"
#include <tuple>


namespace ull {


/// Helper class for extracting children widgets from container
struct children_widgets_extractor {
    /// Returns reference to tuple of children widgets in container
    static auto & get_children(auto & container) {
        return container.children();
    }
};


/// Extracts widgets from single child UI element
template <typename Element>
auto extract_widgets_single(Element && element) {
    if constexpr (std::derived_from<Element, widget_base>) {
        return std::tuple{std::move(element)};
    } else if constexpr (std::derived_from<Element, layout_base>) {
        return std::tuple{std::move(children_widgets_extractor::get_children(element))};
    } else {
        return std::tuple{};
    }
}


/// Extracts widgets from children UI elements
template <typename ... Elements>
auto extract_widgets(Elements && ... elements) {
    return std::tuple_cat(extract_widgets_single(std::move(elements))...);
}


/// Type of tuple containing children widgets for pack of children UI elements
template <typename ... Elements>
using children_widgets_t = decltype(extract_widgets(std::declval<Elements>()...));


}

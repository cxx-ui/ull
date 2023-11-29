
/// \file extract_persistent_properties.hpp
/// Contains definition of the extract_persistent_properties function and related types.

#pragma once

#include "../persistent_property.hpp"


namespace ull {


/// Extracts persistent properties from children UI elements
template <typename ... Elements>
auto extract_persistent_properties(Elements && ... elements) {
    auto extract_single = [](auto && elt) {
        if constexpr (is_persistent_property<std::decay_t<decltype(elt)>>) {
            return std::tuple{std::move(elt)};
        } else {
            return std::tuple{};
        }
    };

    return std::tuple_cat(extract_single(std::forward<Elements>(elements))...);
}


/// Type of tuple containing persistent properties for pack of childrent elements
template <typename ... Elements>
using persistent_properties_t = decltype(extract_persistent_properties(std::declval<Elements>()...));


}

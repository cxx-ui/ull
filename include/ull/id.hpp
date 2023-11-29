
/// \file id.hpp
/// Contains definition of the id property and realted class.

#pragma once

#include <cstddef>
#include <tuple>


namespace ull {

/// Wrapper for string ID of a widget
template <size_t N>
struct id_string {
    /// Constructs widget ID
    constexpr id_string(const char (&str)[N]) {
        for (size_t i = 0; i < N; ++i) {
            value[i] = str[i];
        }
    }

    /// Compares this ID with another
    template <size_t N2>
    constexpr bool operator==(const id_string<N2> & other) const {
        if constexpr (N != N2) {
            return false;
        } else {
            for (size_t i = 0; i < N; ++i) {
                if (value[i] != other.value[i]) {
                    return false;
                }
            }

            return true;
        }
    }

    /// Compares this ID with characters array
    template <size_t N2>
    constexpr bool operator==(const char (&str)[N2]) const {
        return *this == id_string{str};
    }

    char value[N];
};



/// ID property
template <id_string str>
struct id_t {
    /// ID value
    static constexpr auto value = str;
};


/// True if type is ID property instance

template <typename T>
struct is_id_impl {
    static constexpr auto value = false;
};

template <id_string str>
struct is_id_impl<id_t<str>> {
    static constexpr auto value = true;
};

template <typename T>
constexpr inline bool is_id = is_id_impl<T>::value;


/// Widget ID instance
template <id_string str>
constexpr auto id = id_t<str>{};


/// Extracts ID attribute from pack of elements
template <typename ... Elements>
auto extract_id(const Elements & ... elements) {
    // extracting ID elements
    auto extract_ids_single = []<typename Element>(const Element & element) {
        if constexpr (is_id<Element>) {
            return std::tuple{element};
        } else {
            return std::tuple{};
        }
    };
    auto ids = std::tuple_cat(extract_ids_single(elements)...);

    // checking that pack of elements has only single ID element
    static_assert(std::tuple_size_v<decltype(ids)> <= 1 && "widget has multiple IDs");

    // returning ID element if found
    if constexpr (std::tuple_size_v<decltype(ids)> == 1) {
        return std::get<0>(ids);
    }

    // function has void return type if there are not ID elements in the pack
}


/// Type of ID element in pack of elements
template <typename ... Elements>
using widget_id_t = decltype(extract_id(std::declval<Elements>()...));


}

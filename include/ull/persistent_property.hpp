
/// \file persistent_property.hpp
/// Contains definition of traits for persistent properties and related functions.

#pragma once

#include <tuple>


namespace ull {

/// Persistent property trait. All persistent properties must define
/// is_persisten_property template specialization

template <typename Property>
constexpr inline bool is_persistent_property = false;


}

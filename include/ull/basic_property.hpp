
/// \file basic_property.hpp
/// Contains definition of the basic_property class.

#pragma once

#include <type_traits>


namespace ull {


/// Represents property that holds single value
template <typename T>
class basic_property {
public:
    /// Constructs property
    template <typename ... Args>
    requires (std::is_constructible_v<T, Args...>)
    basic_property(Args && ... args):
        value_{std::forward<Args>(args)...} {}

    /// Returns property value
    auto & value() const { return value_; }

private:
    T value_;           ///< Property value
};


}

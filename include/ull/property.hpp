
/// \file property.hpp
/// Contains definition of concepts and types related to widget properties.

#pragma once


namespace ull {


/// The property_for concept is true if apply function is defined for widget
/// and property of specified type
template <typename Widget, typename Property>
concept property_for = requires (Widget & widget, const Property & prop) {
    { apply(widget, std::move(prop)) }
};


}

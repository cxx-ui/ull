
/// \file button.hpp
/// Contains definition of the button widget.

#pragma once

#include "../widget.hpp"
#include "../qt/widgets/button.hpp"
#include "../properties/on_click.hpp"
#include "../properties/text.hpp"


namespace ull {


/// Button widget
template <typename ... Children>
using button = widget_t<button_base, Children...>;


/// Applies text property to a button widget
template <typename Char>
inline void apply(button_base & b, const text<Char> & txt) {
    b.set_text(txt.value());
}


/// Applies on_click property to a button widget
template <typename Handler>
inline void apply(button_base & b, on_click<Handler> & h) {
    auto & impl = h.impl();
    b.set_on_click([&impl] {
        impl.execute();
    });
}


}

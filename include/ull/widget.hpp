
/// \file widget.hpp
/// Contains definition of the widget layout element.

#pragma once

#include "container.hpp"
#include "id.hpp"
#include "layout.hpp"
#include "persistent_property.hpp"
#include "qt/widget_base.hpp"

#include "properties/height.hpp"
#include "properties/width.hpp"

#include "impl/apply_elements.hpp"
#include "impl/extract_layout.hpp"
#include "impl/extract_widgets.hpp"

#include <memory>
#include <tuple>


namespace ull {


/// Helper base class for defining widget ID variable
template <typename ... Elements>
struct widget_t_id_base {
};

template <typename ... Elements>
requires (!std::same_as<widget_id_t<Elements...>, void>)
struct widget_t_id_base<Elements...> {
    static constexpr auto id = widget_id_t<Elements...>::value;
};


/// Helper class for defining widgets with specified base type
template <typename Base, typename ... Elements>
class widget_t: public container<Base, Elements...>, public widget_t_id_base<Elements...> {
    template <typename Base2, typename ... Elements2>
    friend class widget_t;

public:
    /// True if widget has ID
    static constexpr auto has_id = !std::same_as<widget_id_t<Elements...>, void>;

    /// Constructs widget with specified children layout
    widget_t(Elements && ... elements):
        container<Base, Elements...>{std::move(elements)...} {}

    /// Move constructor
    widget_t(widget_t &&) = default;
};


template <typename ... Children>
using widget = widget_t<widget_base, Children...>;


/// Applies widget width proprety
inline void apply(widget_base & widget, const width & w) {
    widget.set_width(w.value());
}

/// Applies widget height proprety
inline void apply(widget_base & widget, const height & h) {
    widget.set_height(h.value());
}

/// Applies child widget
template <typename ChildWidget>
requires std::derived_from<ChildWidget, widget_base>
inline void apply(widget_base & parent, ChildWidget & child) {
    add_child(parent, child);
}


/// Applies ID property to widget. Does nothing
template <id_string str>
void apply(widget_base & w, const id_t<str> &) {
}


}

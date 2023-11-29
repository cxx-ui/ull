
/// \file root_widget.hpp
/// Contains definition of the root_widget class.

#pragma once

#include "../widget.hpp"


namespace ull {


/// The root widget should be used as a root of layout definition.
/// The main purpose of this widget is to set root in all persistent properties
/// after construction.
template <typename Base, typename ... Elements>
class root_widget_t: public widget_t<Base, Elements...> {
public:
    /// Constructs root widget with specified children UI elements.
    /// Sets root to this widget in all persistent properties.
    root_widget_t(Elements && ... elements):
    widget_t<Base, Elements...>{std::move(elements)...} {
        this->update_root(*this);
    }

    /// Displays widget on screen
    void show() {
        widget_base::show();
    }
};


template <typename ... Elements>
using root_widget = root_widget_t<widget_base, Elements...>;


}

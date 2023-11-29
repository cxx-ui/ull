
/// \file qt_widget.hpp
/// Contains definition of the qt_widget template class.

#pragma once

#include "widget_base.hpp"
#include <memory>


namespace ull::qt {


/// Widget based on specific Qt widget
template <typename QtWidget = QWidget>
class qt_widget: public widget_base {
public:
    /// Constrcts platform widget. Creates instance of associated Qt widget
    explicit qt_widget():
        widget_base{std::make_unique<QtWidget>()} {}

    /// Returns reference to associated widget implementation
    QtWidget & impl() {
        return static_cast<QtWidget&>(widget_base::impl());
    }

    /// Returns const reference to associated widget implementation
    const QtWidget & impl() const {
        return static_cast<const QtWidget&>(widget_base::impl());
    }
};


}

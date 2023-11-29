
/// \file platform_layout.hpp
/// Contains definition of the platform_layout template class.

#pragma once

#include "layout_base.hpp"


namespace ull::qt {


/// Base class for layouts implemented with standard Qt layouts
template <typename QtLayout>
class platform_layout: public layout_base {
public:
    /// Constructs layout object. Creates instance of Qt layout object.
    platform_layout():
        layout_base{std::make_unique<QtLayout>()} {}

    /// Returns reference to Qt layout object
    QtLayout & impl() {
        return static_cast<QtLayout&>(layout_base::impl());
    }
};


}

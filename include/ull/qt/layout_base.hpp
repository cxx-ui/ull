
/// \file layout_base.hpp
/// Contains definition of the layout_base class for Qt platform.

#pragma once

#include <memory>
#include <QLayout>


namespace ull::qt {


/// Base class for layouts for Qt platform.
class layout_base {
public:
    /// Constructs layout with specified pointer to Qt layout implementation
    layout_base(std::unique_ptr<QLayout> && imp):
        impl_{std::move(imp)} {}

    /// Returns reference to Qt implementation for layout
    QLayout & impl() { return *impl_; }

    /// Releases Qt layout implementation object
    void release() {
        impl_.release();
    }

private:
    std::unique_ptr<QLayout> impl_;         ///< Unique pointer to Qt layout implementation
};


}


namespace ull {
    using layout_base = qt::layout_base;
}

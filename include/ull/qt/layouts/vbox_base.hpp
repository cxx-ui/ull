
/// \file vbox_base.hpp
/// Contains definition of the vbox_base class for Qt platform.

#pragma once

#include "../platform_layout.hpp"
#include <QVBoxLayout>


namespace ull::qt {


/// Base class for vbox layout for Qt platform.
class vbox_base: public platform_layout<QVBoxLayout> {
public:
    /// Adds widget into layout
    void add(widget_base & w) {
        impl().addWidget(&w.impl());
    }

    /// Adds layout into layout
    void add(layout_base & l) {
        impl().addLayout(&l.impl());
    }
};


/// Adds widget into vbox layout
template <std::derived_from<widget_base> Widget>
void apply(vbox_base & l, Widget & w) {
    l.add(w);
}


/// Adds layout into vbox layout
inline void apply(vbox_base & l, layout_base & l2) {
    l.add(l2);
    l2.release();
}


}

namespace ull {

using vbox_base = qt::vbox_base;


}

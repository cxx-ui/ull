
/// \file hbox_base.hpp
/// Contains definition of the hbox_base class for Qt platform.

#pragma once

#include "../platform_layout.hpp"
#include <QHBoxLayout>


namespace ull::qt {


/// Base class for vbox layout for Qt platform.
class hbox_base: public platform_layout<QHBoxLayout> {
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
void apply(hbox_base & l, Widget & w) {
    l.add(w);
}


/// Adds layout into hbox layout
inline void apply(hbox_base & l, layout_base & l2) {
    l.add(l2);
    l2.release();
}


}

namespace ull {

using hbox_base = qt::hbox_base;


}

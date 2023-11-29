
/// \file widget_base.hpp
/// Contains definition of the widget_base type.

#pragma once

#include "qt/widget_base.hpp"


namespace ull {


/// Sets layout for widget. Sets root for all stored properties in a layout.
/// Stores layout in the widget internal storage.
template <typename Layout>
auto & set_layout(widget_base & w, Layout && layout) {
    auto lptr = std::make_unique<Layout>(std::move(layout));
    apply(w, *lptr);
    lptr->update_root(*lptr);
    auto & res = *lptr.get();
    w.set_stored_layout(std::move(lptr));
    return res;
}


}

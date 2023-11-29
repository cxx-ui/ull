
/// \file vbox.hpp
/// Contains definition of the vbox layout element.

#pragma once

#include "../layout.hpp"
#include "../widget.hpp"
#include "../qt/layouts/vbox_base.hpp"


namespace ull {


/// Vertical box layout
template <typename ... Children>
class vbox: public layout_t<vbox_base, Children...> {
public:
    /// Constructs layout instance
    explicit vbox(Children && ... children):
        layout_t<vbox_base, Children...>{std::move(children)...} {}
};


}

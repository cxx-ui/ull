
/// \file hbox.hpp
/// Contains definition of the hbox layout element.

#pragma once

#include "../layout.hpp"
#include "../widget.hpp"
#include "../qt/layouts/hbox_base.hpp"


namespace ull {


/// Vertical box layout
template <typename ... Children>
class hbox: public layout_t<hbox_base, Children...> {
public:
    /// Constructs layout instance
    explicit hbox(Children && ... children):
        layout_t<hbox_base, Children...>{std::move(children)...} {}
};


}

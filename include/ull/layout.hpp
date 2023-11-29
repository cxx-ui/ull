
/// \file layout.hpp
/// Contains definition of core types related to layouts.

#pragma once

#include "container.hpp"
#include "layout_base.hpp"


namespace ull {


/// Helper class for defining layouts. Contains functions for applying
/// children elements.
template <typename Base, typename ... Elements>
class layout_t: public container<Base, Elements...> {
public:
    /// Constructs layout with specified tree of children elements
    layout_t(Elements && ... elements):
        container<Base, Elements...>{std::move(elements)...} {}
};


}

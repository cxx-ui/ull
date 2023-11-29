
/// \file label.hpp
/// Contains definition of the label widget.

#pragma once

#include "../widget.hpp"
#include "../qt/widgets/label.hpp"


namespace ull {


template <typename ... Children>
using label = widget_t<label_base, Children...>;


template <typename Char>
inline void apply(label_base & label, const text<Char> & txt) {
    label.set_text(txt.value());
}


}

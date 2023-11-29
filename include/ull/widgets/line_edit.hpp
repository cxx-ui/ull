
#pragma once

#include "../widget.hpp"
#include "../qt/widgets/line_edit.hpp"


namespace ull {


// Line edit widget
template <typename ... Elements>
using line_edit = widget_t<line_edit_base, Elements...>;


/// Applies text property to line edit
template <typename Char>
inline void apply(line_edit_base & edit, const text<Char> & txt) {
    edit.set_text(txt.value());
}


}

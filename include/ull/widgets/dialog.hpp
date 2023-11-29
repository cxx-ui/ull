
/// \file dialog.hpp
/// Contains definition of the dialog class.

#pragma once

#include "root_widget.hpp"
#include "../qt/widgets/dialog.hpp"


namespace ull {


/// Dialog box widget
template <typename ... Elements>
class dialog: public root_widget_t<dialog_base, Elements...> {
public:
    /// Constructs dialog with specified child layout items
    dialog(Elements && ... elements):
        root_widget_t<dialog_base, Elements...>{std::move(elements)...} {}
};


}

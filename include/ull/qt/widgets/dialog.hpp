
/// \file dialog.hpp
/// Contains implementation of the dialog widget for Qt platform.

#pragma once

#include "../qt_widget.hpp"
#include <QDialog>


namespace ull::qt {


class dialog_widget: public QDialog {
};


/// Dialog widget implementation for Qt platform.
class dialog_base: public qt_widget<QDialog> {
public:
};


}


namespace ull {
    using dialog_base = qt::dialog_base;
}


/// \file button.hpp
/// Contains implementation of the button widget for Qt platform.

#pragma once

#include "../qt_widget.hpp"
#include <QPushButton>


namespace ull::qt {


/// Button widget implementation for Qt platform
class button_widget: public QPushButton {
public:
    /// Returns button text
    std::wstring text() const {
        return QPushButton::text().toStdWString();
    }

    /// Sets button text
    template <typename Char>
    void set_text(const std::basic_string<Char> & txt) {
        if constexpr (std::same_as<Char, char>) {
            setText(QString::fromStdString(txt));
        } else if constexpr (std::same_as<Char, wchar_t>) {
            setText(QString::fromStdWString(txt));
        }
    }

    /// Sets handler for clicked signal
    template <typename Handler>
    void set_on_click(Handler h) {
        QObject::connect(this, &QPushButton::clicked, h);
    }
};


/// Label widget implementation for Qt platform
class button_base: public qt_widget<QPushButton> {
public:
    /// Returns button text
    std::wstring text() const {
        return impl().text().toStdWString();
    }

    /// Sets button text
    template <typename Char>
    void set_text(const std::basic_string<Char> & txt) {
        if constexpr (std::same_as<Char, char>) {
            impl().setText(QString::fromStdString(txt));
        } else if constexpr (std::same_as<Char, wchar_t>) {
            impl().setText(QString::fromStdWString(txt));
        }
    }

    /// Sets handler for clicked signal
    template <typename Handler>
    void set_on_click(Handler h) {
        QObject::connect(&impl(), &QPushButton::clicked, h);
    }
};


}


namespace ull {
    using button_base = qt::button_base;
}

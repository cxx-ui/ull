
/// \file line_edit.hpp
/// Contains implementation of the line_edit layout widget for the qt engine.

#pragma once

#include "../qt_widget.hpp"
#include <QLineEdit>
#include <iostream>


namespace ull {


/// Line edit widget implementation for Qt platform
class line_edit_widget: public QLineEdit {
public:
    /// Returns text in line edit
    std::wstring text() const {
        return QLineEdit::text().toStdWString();
    }

    /// Sets text in line edit
    template <typename Char>
    void set_text(const std::basic_string<Char> & txt) {
        if constexpr (std::same_as<Char, char>) {
            setText(QString::fromStdString(txt));
        } else if constexpr (std::same_as<Char, wchar_t>) {
            setText(QString::fromStdWString(txt));
        }
    }
};


/// Line edit widget implementation for Qt platform
class line_edit_base: public qt::qt_widget<QLineEdit> {
public:
    /// Returns text in line edit
    std::wstring text() const {
        return impl().text().toStdWString();
    }

    /// Sets text in line edit
    template <typename Char>
    void set_text(const std::basic_string<Char> & txt) {
        if constexpr (std::same_as<Char, char>) {
            impl().setText(QString::fromStdString(txt));
        } else if constexpr (std::same_as<Char, wchar_t>) {
            impl().setText(QString::fromStdWString(txt));
        }
    }
};


}

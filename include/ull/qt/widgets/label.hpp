
/// \file label.hpp
/// Contains implementation of the label widget for Qt platform.

#pragma once

#include "../qt_widget.hpp"
#include <QLabel>


namespace ull::qt {


/// Label widget implementation for Qt platform
class label_widget: public QLabel {
public:
    /// Returns text in label
    std::wstring text() const {
        return QLabel::text().toStdWString();
    }

    /// Sets label text
    template <typename Char>
    void set_text(const std::basic_string<Char> & txt) {
        if constexpr (std::same_as<Char, char>) {
            setText(QString::fromStdString(txt));
        } else if constexpr (std::same_as<Char, wchar_t>) {
            setText(QString::fromStdWString(txt));
        }
    }
};


/// Label widget implementation for Qt platform
class label_base: public qt_widget<QLabel> {
public:
    /// Returns text in label
    std::wstring text() const {
        return impl().text().toStdWString();
    }

    /// Sets label text
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


namespace ull {
    using label_base = qt::label_base;
}

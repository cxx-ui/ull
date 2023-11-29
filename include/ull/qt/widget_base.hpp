
/// \file widget_base.hpp
/// Contains definition of the widget_base class for Qt implementation

#pragma once

#include "layout_base.hpp"
#include <QWidget>
#include <memory>


namespace ull::qt {


/// Base class for all widgets
class widget_base {
public:
    /// Constructs widget. Creates associated QWidget instance
    widget_base():
        impl_{std::make_unique<QWidget>()} {}

    /// Constructs widget from pointer to Qt widget implementation
    widget_base(std::unique_ptr<QWidget> && impl):
        impl_{std::move(impl)} {}

    /// Move constructor
    widget_base(widget_base &&) = default;

    /// Deleted copy constructor
    widget_base(const widget_base &) = delete;

    /// Deleted copy-assignment operator
    widget_base & operator=(const widget_base &) = delete;

    /// Default move-assignment operator
    widget_base & operator=(widget_base &&) = default;

    /// Default virtual destructor
    virtual ~widget_base() = default;

    /// Sets widget width
    void set_width(int w) {
        impl().setFixedWidth(w);
    }

    /// Sets widget height
    void set_height(int h) {
        impl().setFixedHeight(h);
    }

    /// Returns reference to associated Qt widget implementation
    QWidget & impl() {
        assert(impl_ && "widget implementation is empty");
        return *impl_;
    }

    /// Returns const reference to associated Qt widget implementation
    const QWidget & impl() const {
        assert(impl_ && "widget implementation is empty");
        return *impl_;
    }

    /// Sets stored widget layout
    void set_stored_layout(std::unique_ptr<layout_base> && l) {
        layout_ = std::move(l);
    }

protected:
    /// Displays widget on screen. Should be accessible only for root widgets
    void show() {
        impl().show();
    }

private:
    std::unique_ptr<QWidget> impl_;         ///< Unique pointer to Qt widget implementation
    std::unique_ptr<layout_base> layout_;   ///< Optional pointer to stored widget layout
};


}

namespace ull {

using widget_base = qt::widget_base;

/// Adds child widget to parent
void add_child(widget_base & parent, widget_base & child) {
    child.impl().setParent(&parent.impl());
}


/// Applies layout to widget
inline void apply(widget_base & w, layout_base & l) {
    w.impl().setLayout(&l.impl());
    l.release();
}


}

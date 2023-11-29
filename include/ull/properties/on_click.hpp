
/// \file on_click.hpp
/// Contains definition of the on_click widget property.

#pragma once

#include "../basic_property.hpp"
#include "../persistent_property.hpp"
#include <functional>
#include <memory>


namespace ull {


/// Implementation of on_click property
template <typename Handler>
class on_click_impl {
public:
    /// Constructs instance with specified user defined handler
    on_click_impl(Handler && handler):
        handler_{std::move(handler)} {}

    /// Deleted move constructor
    on_click_impl(on_click_impl &&) = delete;

    /// Sets handler with root parameter
    void set_handler_with_root(const std::function<void()> & h) {
        handler_with_root_ = h;
    }

    /// Sets reference to root object to pass to handler
    template <typename Root>
    void set_root(Root & root) {
        handler_with_root_ = [this, &root] {
            handler_(root);
        };
    }

    /// Executes handler
    void execute() {
        handler_with_root_();
    }

private:
    Handler handler_;
    std::function<void ()> handler_with_root_;
};


/// Click handler for various widgets
template <typename Handler>
class on_click {
    using on_click_impl_t = on_click_impl<Handler>;

public:
    /// Constructs property with specified handler value
    on_click(Handler && h):
        impl_{std::make_unique<on_click_impl_t>(std::move(h))} {}

    /// Sets reference to root object to pass to handler
    template <typename Root>
    void set_root(Root & root) {
        impl_->set_root(root);
    }

    /// Returns reference to property implementation
    auto & impl() { return *impl_; }

private:
    std::unique_ptr<on_click_impl_t> impl_;
};


template <typename Handler>
constexpr inline auto is_persistent_property<on_click<Handler>> = true;


/// Updates root in on_click property
template <typename Handler, typename Root>
void set_root(on_click<Handler> & h, Root & root) {
    h.set_root(root);
}


}

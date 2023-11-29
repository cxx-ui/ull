
/// \file platform_widget.hpp
/// Contains definition of the platform_widget class for Qt platform.

#pragma once


namespace ull::qt {


template <typename QtBaseWidget>
class platform_widget: public QtBaseWidget {
public:
    template <typename Layout>
    auto & set_layout(Layout && layout) {
        auto l_uptr = std::make_unique<Layout>(std::move(layout));
        apply(*l_uptr, *l_uptr);
        l_uptr->update_root(*l_uptr);
        auto & res = *l_uptr.get();
        stored_layout_ = std::move(l_uptr);
        return res;
    }

private:
    std::unique_ptr<layout_base> stored_layout_;
};


template <typename QtBaseWidget, typename ... Elements>
class platform_widget_t: public platform_widget<QtBaseWidget> {
public:
    platform_widget_t(Elements && ...elements) {
    }
};


template <typename ... Elements>
using platform_widget_widget = platform_widget_t<QWidget, Elements...>;


}

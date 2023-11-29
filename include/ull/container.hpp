
/// \file container.hpp
/// Contains definition of the container template class.

#pragma once

#include "impl/apply_elements.hpp"
#include "impl/extract_widgets.hpp"
#include "impl/extract_persistent_properties.hpp"
#include "id.hpp"
#include "persistent_property.hpp"


namespace ull {

/// Container for other widgets
template <typename Base, typename ... Elements>
class container: public Base {
    template <typename Base2, typename ... Elements2>
    friend class container;

    friend struct children_widgets_extractor;

public:
    /// Type of tuple containing children widgets
    using children_t = children_widgets_t<Elements...>;


private:
    /// Returns child widget with specified ID. void is returned id child not found
    template <id_string str, size_t Idx>
    static constexpr decltype(auto) get_child_impl(children_t & children) {
        if constexpr (Idx == std::tuple_size_v<children_t>) {
            // returning void
            return;
        } else {
            using child_t = std::tuple_element_t<Idx, children_t>;
            if constexpr (child_t::has_id) {
                if constexpr (child_t::id == str) {
                    return std::get<Idx>(children);
                } else {
                    return get_child_impl<str, Idx + 1>(children);
                }
            } else {
                return get_child_impl<str, Idx + 1>(children);
            }
        }
    }


public:
    /// Constructs widget with specified children layout
    container(Elements && ... elements):
    children_{(apply_elements(static_cast<Base&>(*this), elements...), extract_widgets(std::move(elements)...))},
    persistent_properties_{extract_persistent_properties(std::move(elements)...)} {
    }

    /// Move constructor
    container(container &&) = default;

    /// Returns reference to tuple of persistent properties
    auto & persistent_properties() const {
        return persistent_properties_;
    }

    /// Returns reference to child widget at specified index
    template <size_t Idx>
    auto & child() {
        return std::get<Idx>(children_);
    }

    /// True if widget has child widget with specified ID
    template <id_string str>
    static constexpr bool has_child = !std::same_as<decltype(get_child_impl<str, 0>(std::declval<children_t&>())), void>;

    /// Returns reference to child widget with specified ID
    template <id_string str>
    requires (has_child<str>)
    decltype(auto) child() {
        return get_child_impl<str, 0>(children_);
    }

    /// Returns reference to child widget with specified ID
    template <id_string str>
    requires (has_child<str>)
    decltype(auto) child_widget() {
        return this->child<str>().impl();
    }

    /// Updates root for all persistent properties and child widgets
    template <typename Root>
    void update_root(Root & root) {
        // updating root for all persistent properties
        auto update_props = [&root](auto && ... props) {
            (set_root(props, root), ...);
        };
        std::apply(update_props, persistent_properties_);

        // updating root for all children widgets
        auto update_children = [&root](auto && ... children) {
            (children.update_root(root), ...);
        };
        std::apply(update_children, children_);
    }

    /// Returns reference to children widgets
    children_t & children() {
        return children_;
    }


private:
    /// Tuple of children widgets
    children_t children_;

    /// Persistent properties for widget
    persistent_properties_t<Elements...> persistent_properties_;
};


}

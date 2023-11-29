
/// \file apply.hpp
/// Contains definition of the apply_elements function.

#pragma once


namespace ull {


/// Applies children UI elements to object
template <typename Object, typename ... Elements>
void apply_elements(Object & obj, Elements & ... elements) {
    (apply(obj, elements), ...);
}


}

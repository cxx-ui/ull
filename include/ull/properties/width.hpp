
/// \file width.hpp
/// Contains definition of the width property.

#pragma once

#include "../basic_property.hpp"


namespace ull {


/// Width property
struct width: public basic_property<int> {
    using basic_property<int>::basic_property;
};


}

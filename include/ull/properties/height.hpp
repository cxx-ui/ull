
/// \file height.hpp
/// Contains definition of the height proprety.hpp

#pragma once

#include "../basic_property.hpp"


namespace ull {


/// Height property
struct height: public basic_property<int> {
    using basic_property<int>::basic_property;
};


}

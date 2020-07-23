//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "graphics_drawer.hpp"

void graphics_drawer::draw_all()
{
    for (uint_fast8_t i = 0; i < drawings_c; i++)
    {
        drawings[i]->draw(*this);
    }
}

graphics_drawer& graphics_drawer::operator<<(hwlib::drawable& drawing)
{
    drawings[drawings_c] = &drawing;
    drawings_c++;
    return *this;
}
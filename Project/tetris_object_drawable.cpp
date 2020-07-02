//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "tetris_object_drawable.hpp"

void tetris_object_drawable::draw_implementation(hwlib::window& w, hwlib::xy pos, hwlib::color color)
{
    w.write(pos, color);
}

void tetris_object_drawable::draw(hwlib::window& w)
{
    switch(type)
    {
        case tetrisTypes::box:
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    draw_implementation(w, hwlib::xy((pos.x - i)  - offset.x, pos.y - j), hwlib::color(0xFFFF00));
                }
            }
            break;
        case tetrisTypes::line:
            for (int i = 0; i < 4; i++)
            {
                draw_implementation(w, hwlib::xy((pos.x - i) - offset.x, pos.y), hwlib::color(0x00FFFF));
            }           
            break;
        case tetrisTypes::piramide:
            for (int i = 0; i < 3; i++)
            {
                draw_implementation(w, hwlib::xy(pos.x  - offset.x, pos.y - i), hwlib::purple);

                if(i == 1) draw_implementation(w, hwlib::xy((pos.x - 1)  - offset.x, pos.y - i), hwlib::purple);
            }           
            break;
    }
}
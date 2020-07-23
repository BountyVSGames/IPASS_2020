//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "tetris_object_drawable.hpp"

void tetrisObjectDrawable::draw_implementation(hwlib::window& w, hwlib::xy pos, hwlib::color color)
{
    w.write(pos, color);
}

void tetrisObjectDrawable::draw(hwlib::window& w)
{
    switch(type)
    {
        case tetrisTypes::box:
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    draw_implementation(w, hwlib::xy((pos.x - i), pos.y - j), hwlib::color(0xFFFF00));
                }
            }
            break;
        case tetrisTypes::line:
            for (int i = 0; i < 4; i++)
            {
                draw_implementation(w, hwlib::xy((pos.x - i), pos.y), hwlib::color(0x00FFFF));
            }           
            break;
        case tetrisTypes::piramide:
            for (int i = 0; i < 3; i++)
            {
                draw_implementation(w, hwlib::xy(pos.x, pos.y - i), hwlib::purple);

                if(i == 1) 
                {
                    draw_implementation(w, hwlib::xy(pos.x - 1, pos.y - i), hwlib::purple);
                }
            }           
            break;
    }
}

void tetrisObjectDrawable::update()
{
    if(pos.x < 31)
    {
        pos.x++;
    }
}

void tetrisObjectDrawable::moveX(int posX)
{
    if((pos.y < 15 && posX > 0) || (pos.y > 1 && posX < 0))
    {
        pos.y += posX;
    }
}
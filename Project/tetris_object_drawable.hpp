//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef TETRISOBJECTDRAWABLE_HPP
#define TETRISOBJECTDRAWABLE_HPP

#include "hwlib.hpp"

#include "enums.hpp"
#include "updating_drawable.hpp"

class tetris_object_drawable : public hwlib::drawable
{
    protected:
        bool active;

        const tetrisTypes type;
        hwlib::xy pos;
        hwlib::color color;

        virtual void draw_implementation(hwlib::window& w, hwlib::xy pos, hwlib::color color);
    public:
        hwlib::xy offset = hwlib::xy(0,0);

        tetris_object_drawable(tetrisTypes type, hwlib::xy pos)
            : drawable{pos}, type(type), pos(pos)
            {
                active = false;
            };
        
        void draw(hwlib::window& w);

        void set_position(hwlib::xy newPos)
        {
            pos = newPos;
        }
};

#endif
//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef TETRISOBJECTDRAWABLE_HPP
#define TETRISOBJECTDRAWABLE_HPP

#include "hwlib.hpp"
#include "enums.hpp"

class tetrisObjectDrawable : public hwlib::drawable
{
    protected:
        bool active;

        tetrisTypes type;
        hwlib::xy pos;
        hwlib::color color;

        //tetrisObjectDrawable *nextObject;

        virtual void draw_implementation(hwlib::window& w, hwlib::xy pos, hwlib::color color);
    public:
        tetrisObjectDrawable(tetrisTypes type = static_cast<tetrisTypes>(0), hwlib::xy pos = hwlib::xy(7,0))
            : drawable{pos}, type(type), pos(pos)
            {
                active = false;
            };
        
        void draw(hwlib::window& w);
        void update();
        void moveX(int posX);
};

#endif
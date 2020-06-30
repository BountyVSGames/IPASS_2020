#ifndef UPDATINGDRAWABLE_HPP
#define UPDATINGDRAWABLE_HPP

#include "hwlib.hpp"

class updating_drawable : public hwlib::drawable
{
    public:
        updating_drawable(hwlib::xy start) : hwlib::drawable(start){};

        virtual void draw(hwlib::window& w) = 0;

        virtual void update(){};
};

#endif
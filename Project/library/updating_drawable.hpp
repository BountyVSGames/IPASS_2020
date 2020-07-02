//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef UPDATINGDRAWABLE_HPP
#define UPDATINGDRAWABLE_HPP

#include "hwlib.hpp"

/**
 * @class updating_drawable
 * @author Boudewijn Witteveen
 * @date 02/07/20
 * @file updating_drawable.hpp
 * @brief Inherits hwlib::drawable. Adds update function
 */
class updating_drawable : public hwlib::drawable
{
    public:
        updating_drawable(hwlib::xy start) : hwlib::drawable(start){};

        /**
            * @brief Gets called everytime tetris_object_drawable requires a draw
        */
        virtual void draw(hwlib::window& w) = 0;

        /**
            * @brief Updates every frame
        */
        virtual void update(){};
};

#endif
//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef GRAPHICSDRAWER_HPP
#define GRAPHICSDRAWER_HPP

#include "updating_drawable.hpp"
#include "hwlib.hpp"

/**
 * @class matrix
 * @author Boudewijn Witteveen
 * @date 02/07/20
 * @file graphics_drawer.hpp
 * @brief Inherits hwlib::window.
 */
class graphics_drawer : public hwlib::window
{
    protected:
        uint_fast16_t drawings_c = 0;
        hwlib::drawable* drawings[128];

        uint_fast16_t updating_drawings_c = 0;
        updating_drawable* updating_drawings[128];
    public:
        /**
         * @brief hwlib::window with the ability to store drawable to draw continuously
        */
        graphics_drawer(hwlib::xy size, hwlib::color foreground, hwlib::color background) 
            : hwlib::window(size, foreground, background)
            {};
        
        void draw_all();
        void update_all();

        graphics_drawer& operator<<(hwlib::drawable& drawing);
        graphics_drawer& operator<<(updating_drawable& drawing); 
};

#endif
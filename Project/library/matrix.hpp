//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "graphics_drawer.hpp"
#include "matrix_part.hpp"
#include "matrix_port.hpp"
#include "hwlib.hpp"

/**
 * @class matrix
 * @author Boudewijn Witteveen
 * @date 02/07/20
 * @file matrix.hpp
 * @brief Inherits graphics_drawer. Manages the matrix
 */
class matrix : public graphics_drawer
{
    private:
        matrix_port& port;
        matrix_part top;
        matrix_part bottom;

        virtual void write_implementation(hwlib::xy l, hwlib::color c);
    public:
        matrix(matrix_port& port, hwlib::color fg = hwlib::white, hwlib::color bg = hwlib::black)
            : graphics_drawer(hwlib::xy(32, 16), fg, bg), port(port), top(port.rgb0), bottom(port.rgb1)
            {}
        
        void showFrame();
        void loop();
        
        virtual void flush(){};
        virtual void clear();
};

#endif
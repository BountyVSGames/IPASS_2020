//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef MATRIXPART_HPP
#define MATRIXPART_HPP

#include "matrix_pins_rgb.hpp"
#include "hwlib.hpp"

/**
 * @class matrix_part
 * @author Boudewijn Witteveen
 * @date 02/07/20
 * @file matrix_part.hpp
 * @brief Writes pixel data to the matrix
 */
class matrix_part
{
    private:
        matrix_pins_rgb& rgb;
    public:
        hwlib::color pixels[8][32];

        matrix_part(matrix_pins_rgb& rgb) : rgb(rgb) {}
        
        void write(const hwlib::xy l, hwlib::color c)
        {
            pixels[l.y][l.x] = c;
        }

        void emit(uint_fast8_t c)
        {
            rgb.write(c);
        }
};

#endif
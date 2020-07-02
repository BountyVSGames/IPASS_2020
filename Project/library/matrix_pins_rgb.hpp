//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef MATRIXPINSRGB_HPP
#define MATRIXPINSRGB_HPP

#include "hwlib.hpp"

/**
 * @class matrix_pins_rgb
 * @author Boudewijn Witteveen
 * @date 02/07/20
 * @file matrix_pins_rgb.hpp
 * @brief Inherits hwlib::port_out. Manages the rgb pins
 */
class matrix_pins_rgb : public hwlib::port_out
{
    private:
        hwlib::pin_out& r;
        hwlib::pin_out& g;
        hwlib::pin_out& b;
        public:
            /**
	            * @copydoc hwlib::port_out::number_of_pins()
	        */
            uint_fast8_t number_of_pins() 
            {
		        return 3;
	        }

            matrix_pins_rgb(hwlib::pin_out& r, hwlib::pin_out& g, hwlib::pin_out& b) : 
                r(r), g(g), b(b)
                {};
        
            /**
                * @brief Writes bit value to the rgb ports
                * @param color RGB value
            */
            void write(uint_fast8_t color)
            {
                r.write(color& 0b100);
                g.write(color& 0b010);
                b.write(color& 0b001);
            }

            /**
	            * @copydoc hwlib::port_out::flush()
	        */
            void flush()
            {
                r.flush();
                g.flush();
                b.flush();
            }
};

#endif
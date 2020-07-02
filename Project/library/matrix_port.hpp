//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef MATRIXPORT_HPP
#define MATRIXPORT_HPP

#include "matrix_pins_rgb.hpp"

/**
 * @class matrix_port
 * @author Boudewijn Witteveen
 * @date 02/07/20
 * @file matrix_port.hpp
 * @brief Contains all of the ports from the arduino that connect to the rgb matrix
 */
class matrix_port
{
    public:
        matrix_pins_rgb& rgb0;
        matrix_pins_rgb& rgb1;
        hwlib::port_out& address;
        hwlib::pin_out& clock;
        hwlib::pin_out& latch;
        hwlib::pin_out & output_enabled;

        matrix_port(matrix_pins_rgb& rgb0, matrix_pins_rgb& rgb1, hwlib::port_out& address, hwlib::pin_out& clock, hwlib::pin_out& latch, hwlib::pin_out& output_enabled):
            rgb0(rgb0), rgb1(rgb1), address(address), clock(clock), latch(latch), output_enabled(output_enabled)
            {};
};

#endif
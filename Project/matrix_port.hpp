#ifndef MATRIXPORT_HPP
#define MATRIXPORT_HPP

#include "matrix_pins_rgb.hpp"

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
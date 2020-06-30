#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "graphics_drawer.hpp"
#include "matrix_part.hpp"
#include "matrix_port.hpp"
#include "hwlib.hpp"

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
        
        void show_frame();
        void loop();
        
        virtual void flush(){};
        virtual void clear();
};

#endif
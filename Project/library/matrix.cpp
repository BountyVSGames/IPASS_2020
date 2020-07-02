//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "matrix.hpp"

void matrix::write_implementation(hwlib::xy l, hwlib::color c)
{
    if(l.y < 8)
    {
        top.write(l, c);
    }
    else if(l.y < 16)
    {
        bottom.write(l - hwlib::xy(0,8), c);
    }
}

void matrix::show_frame()
{
    clear();
    update_all();
    draw_all();

    for (uint_fast8_t c = 0; c < 4; c++)
    {
        for (uint_fast8_t y = 0; y < 8; y++)
        {
            for (uint_fast8_t x = 0; x < 32; x++)
            {
                uint_fast8_t r = top.pixels[y][x].red;
                uint_fast8_t g = top.pixels[y][x].green;
                uint_fast8_t b = top.pixels[y][x].blue;
                uint_fast8_t rgb = (r >= c) << 2 | (g >= c) << 1 | (b >= c);
                top.emit(rgb);

                r = bottom.pixels[y][x].red;
                g = bottom.pixels[y][x].green;
                b = bottom.pixels[y][x].blue;
                rgb = (r >= c) << 2 | (g >= c) << 1 | (b >= c);
                bottom.emit(rgb);

                port.clock.write(0);
                port.clock.write(1);
            }

            port.output_enabled.write(1);
            port.address.write(y);
            port.latch.write(1);
            port.latch.write(0);
            port.output_enabled.write(0);        
        }      
    } 
}

void matrix::loop()
{
    for(;;)
    {
        show_frame();
    }
}

void matrix::clear()
{
    for (int_fast16_t y = 0; y < size.y; y++)
    {
        for (int_fast16_t x = 0; x < size.x; x++)
        {
            write_implementation(hwlib::xy(x,y), background);
        }   
    }
}
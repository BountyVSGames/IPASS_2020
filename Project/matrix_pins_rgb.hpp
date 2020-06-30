#ifndef MATRIXPINSRGB_HPP
#define MATRIXPINSRGB_HPP

#include "hwlib.hpp"
    
class matrix_pins_rgb : public hwlib::port_out
{
    private:
        hwlib::pin_out& r;
        hwlib::pin_out& g;
        hwlib::pin_out& b;
        public:
            uint_fast8_t number_of_pins() 
            {
		        return 3;
	        }

            matrix_pins_rgb(hwlib::pin_out& r, hwlib::pin_out& g, hwlib::pin_out& b) : 
                r(r), g(g), b(b)
                {};
        
            void write(uint_fast8_t c)
            {
                r.write(c& 0b100);
                g.write(c& 0b010);
                b.write(c& 0b001);
            }

            void flush()
            {
                r.flush();
                g.flush();
                b.flush();
            }
};

#endif
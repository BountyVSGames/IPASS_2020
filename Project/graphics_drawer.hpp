#ifndef GRAPHICSDRAWER_HPP
#define GRAPHICSDRAWER_HPP

#include "updating_drawable.hpp"
#include "hwlib.hpp"

class graphics_drawer : public hwlib::window
{
    protected:
        uint_fast16_t drawings_c = 0;
        hwlib::drawable* drawings[128];

        uint_fast16_t updating_drawings_c = 0;
        updating_drawable* updating_drawings[128];
    public:
        graphics_drawer(hwlib::xy size, hwlib::color foreground, hwlib::color background) 
            : hwlib::window(size, foreground, background)
            {};
        
        void draw_all();
        void update_all();

        graphics_drawer& operator<<(hwlib::drawable& drawing);
        graphics_drawer& operator<<(updating_drawable& drawing); 
};

#endif
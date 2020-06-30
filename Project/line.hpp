#ifndef LINE_HPP
#define LINE_HPP

#include "hwlib.hpp"

class line
{
    private: 
        hwlib::window & w;
        int startXPos;
        int startYPos;
        int endXPos;
        int endYPos;
    public:
        line(
            hwlib::window & w, 
            int newStartXPos, 
            int newStartYPos,
            int newEndXPos,
            int newEndYPos
        ):
            w(w)
        {
            startXPos = newStartXPos;
            startYPos = newStartYPos;
            endXPos = newEndXPos;
            endYPos = newEndYPos;
        }

        void print();
};

#endif
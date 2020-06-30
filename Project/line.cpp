#include "line.hpp"

void line::print()
{
    hwlib::line line
    (
        hwlib::xy(startXPos, startYPos),
        hwlib::xy(endXPos, endYPos)
    );

    line.draw(w);
    w.flush();
}
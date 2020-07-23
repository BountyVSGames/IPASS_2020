//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "hwlib.hpp"

#include "library/matrix.hpp"
#include "library/matrix_pins_rgb.hpp"
#include "enums.hpp"

#include <vector>

#include "tetris_object_drawable.hpp"

void movementObject(tetrisObjectDrawable& object, float& verticalDelay, float& horizontalDelay)
{
	auto buttonLeft = hwlib::target::pin_in(hwlib::target::pins::d52);
	auto buttonRight = hwlib::target::pin_in(hwlib::target::pins::d53);

	buttonLeft.refresh();
	buttonRight.refresh();

	if((buttonLeft.read() == 1 || buttonRight.read() == 1) && horizontalDelay <= 0)
	{
		object.moveX(buttonLeft.read() ? 1 : -1);

		horizontalDelay = 50;
	}
	else
	{
		horizontalDelay--;
	}

	if(verticalDelay <= 0)
	{
		object.update();

		verticalDelay = 100;
	}
	else
	{
		verticalDelay--;
	}	
}

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
	
	auto r0 = hwlib::target::pin_out(hwlib::target::pins::d32);
	auto g0 = hwlib::target::pin_out(hwlib::target::pins::d29);
	auto b0 = hwlib::target::pin_out(hwlib::target::pins::d27);
	matrix_pins_rgb rgb0 = matrix_pins_rgb(r0, g0, b0);

	auto r1 = hwlib::target::pin_out(hwlib::target::pins::d30);
	auto g1 = hwlib::target::pin_out(hwlib::target::pins::d28);
	auto b1 = hwlib::target::pin_out(hwlib::target::pins::d26);
	matrix_pins_rgb rgb1 = matrix_pins_rgb(r1, g1, b1);

    auto a = hwlib::target::pin_out(hwlib::target::pins::d33);
	auto b = hwlib::target::pin_out(hwlib::target::pins::d34);
	auto c = hwlib::target::pin_out(hwlib::target::pins::d35);
	auto my_address_port = hwlib::port_out_from_pins_t(a, b, c);

	auto clock = hwlib::target::pin_out(hwlib::target::pins::d37);
	auto latch = hwlib::target::pin_out(hwlib::target::pins::d38);
	auto output_enabled = hwlib::target::pin_out(hwlib::target::pins::d36);

    auto my_rgb_port = matrix_port(rgb0, rgb1, my_address_port, clock, latch, output_enabled);
	auto my_window = matrix(my_rgb_port);

	float verticalDelay = 100;
	float horizontalDelay = 0;

	tetrisTypes test1 = static_cast<tetrisTypes>(0);
	//tetrisTypes test2 = static_cast<tetrisTypes>(1);
	//tetrisTypes test3 = static_cast<tetrisTypes>(2);
	hwlib::xy position1(0,7);

	tetrisObjectDrawable object1 = tetrisObjectDrawable(test1, position1);

	my_window << object1;

    for (;;)
    {	
		movementObject(object1, verticalDelay, horizontalDelay);
		
		my_window.showFrame();
    }
}
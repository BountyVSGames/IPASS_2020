//          Copyright Boudewijn Witteveen 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "hwlib.hpp"

#include "library/matrix.hpp"
#include "library/matrix_pins_rgb.hpp"

#include "tetris_object_drawable.hpp"

//tetris_object_drawable* allTetrisObjects[100];

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

	auto block1 = tetris_object_drawable(tetrisTypes.box, hwlib::xy(5, 4));
	auto block2 = tetris_object_drawable(tetrisTypes.line, hwlib::xy(5, 8));
	auto block3 = tetris_object_drawable(tetrisTypes.piramide, hwlib::xy(5, 12));

	float verticalDelay = 100;

    for (;;)
    {	
		if(verticalDelay <= 0)
		{
			block1.offset.x--;
			block2.offset.x--;
			block3.offset.x--;

			verticalDelay = 100;
		}
		else
		{
			verticalDelay--;
		}
		

		my_window.show_frame();
    }
}
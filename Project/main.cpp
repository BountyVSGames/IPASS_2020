#include "hwlib.hpp"

#include "matrix.hpp"
#include "matrix_pins_rgb.hpp"

#include "line.hpp"

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

	hwlib::line line
    (
        hwlib::xy(0, 16),
        hwlib::xy(0, 0),
		hwlib::red
    );

	hwlib::line line2
    (
        hwlib::xy(0, 0),
        hwlib::xy(16, 16),
		hwlib::red
    );

	my_window << line;
	//my_window << line2;

    for (;;)
    {
		my_window.show_frame();
    }
    
}
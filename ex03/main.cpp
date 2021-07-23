#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Fixed.hpp"


int	main( void ) {

	Point p1;
	Point p2(-0.1f, 4);
	Point p3(4, 2);

	Point p4(0, -1);
	Point p5(2, 2);

	// Point p6;
	// p6 = p3;

	Point p7(p2);

	std::cout << bsp(p1, p7, p3, p4) << std::endl;
	std::cout << bsp(p1, p7, p3, p5) << std::endl;

	return 0;
}

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp_vector(Point const a, Point const b, Point const c, Point const point){
	Fixed r1 = (a.getX() - point.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (a.getY() - point.getY());
	Fixed r2 = (b.getX() - point.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (b.getY() - point.getY());
	Fixed r3 = (c.getX() - point.getX()) * (a.getY() - c.getY()) - (a.getX() - c.getX()) * (c.getY() - point.getY());
	if ((r1 > 0 && r2 > 0 && r3 > 0) || (r1 < 0 && r2 < 0 && r3 < 0))
		return (true);
	else
		return (false);
}

bool	bsp_check(Point const a, Point const b, Point const c, Point const point){
	Fixed k = (a.getY() - b.getY()) / (a.getX() - b.getX());
	Fixed m = b.getY() - (b.getX() * k);
	Fixed yc = k * c.getX() + m;
	Fixed ypoint = k * point.getX() + m;
	if ((c.getY() < yc && point.getY() < ypoint) || (c.getY() > yc && point.getY() > ypoint))
		return (true);
	else
		return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){
	if (!bsp_check(a, b, c, point))
		return (false);
	if (!bsp_check(b, c, a, point))
		return (false);
	if (!bsp_check(a, c, b, point))
		return (false);
	return (true);
}

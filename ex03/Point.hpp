#pragma once
#ifndef __POINT_H__
# define __POINT_H__
# include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point(void);
		~Point(void);
		Point( const Point &tocopy );
		Point( const float x, const float y );
		Point& operator = (const Point &tocopy );
		Fixed const getX( void ) const;
		Fixed const getY( void ) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

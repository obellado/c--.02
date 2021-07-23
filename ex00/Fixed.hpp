#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed{
	private:
		int						_pointValue;
		static const int 		_nOfFractionalBits = 8;


	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &tocopy );
		Fixed& operator = (const Fixed &tocopy );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif

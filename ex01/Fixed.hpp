#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed{
	private:
		int						_pointValue;
		static const int 		_nOfFractionalBits;


	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &tocopy );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed& operator = (const Fixed &tocopy );

		Fixed( int const i );
		Fixed( float const i );

		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream& operator << ( std::ostream & o, const Fixed &fix );

#endif

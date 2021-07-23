#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_nOfFractionalBits = 8;

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_pointValue = 0;
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &tocopy ){
	std::cout << "Copy constructor called" << std::endl;
	this->_pointValue = tocopy.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &tocopy ){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &tocopy)
		this->_pointValue = tocopy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	return (this->_pointValue);
}

void	Fixed::setRawBits( int const raw ) {
	this->_pointValue = raw;
	return ;
}

Fixed::Fixed( int const i ) {
	std::cout << "Int constructor called" << std::endl;
	this->_pointValue = i * (1 << Fixed::_nOfFractionalBits);
}

Fixed::Fixed( float const i ) {
	std::cout << "Float constructor called" << std::endl;
	this->_pointValue = roundf(i * (1 << Fixed::_nOfFractionalBits));
}

std::ostream &	operator<< ( std::ostream & o, const Fixed &fix ) {
	o << fix.toFloat();
	return o;
}

float Fixed::toFloat( void ) const {
	return ((float)this->_pointValue / (float)(1 << Fixed::_nOfFractionalBits));
}

int Fixed::toInt( void ) const {
	return (roundf((float)this->_pointValue / (float)(1 << Fixed::_nOfFractionalBits)));
}

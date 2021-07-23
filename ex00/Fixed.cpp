#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_pointValue = 0;
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &tocopy ){
	std::cout << "Copy constructor called" << std::endl;
	*this = tocopy;
}

Fixed& Fixed::operator = (const Fixed &tocopy ){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &tocopy)
		this->_pointValue = tocopy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_pointValue);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_pointValue = raw;
	return ;
}

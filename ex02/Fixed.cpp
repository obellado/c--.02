#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_nOfFractionalBits = 8;

Fixed::Fixed( void ) {
	this->_pointValue = 0;
}

Fixed::~Fixed( void ){
}

Fixed::Fixed( const Fixed &tocopy ){
	this->_pointValue = tocopy.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &tocopy ){
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
	this->_pointValue = i * (1 << Fixed::_nOfFractionalBits);
}

Fixed::Fixed( float const i ) {
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

Fixed Fixed::operator+ (const Fixed & one) const {
	Fixed r;
	r.setRawBits(this->_pointValue + one.getRawBits());
	return r;
}

Fixed Fixed::operator- (const Fixed &one) const {
	Fixed r;
	r.setRawBits(this->_pointValue - one.getRawBits());
	return r;
}

Fixed Fixed::operator* (const Fixed &one) const {
	Fixed r;
	r.setRawBits(this->_pointValue * one.getRawBits() >> Fixed::_nOfFractionalBits);
	return r;
}

Fixed Fixed::operator/ (const Fixed &one) const {
	Fixed r;
	r.setRawBits((this->_pointValue << Fixed::_nOfFractionalBits) / one.getRawBits());
	return r;
}

Fixed& Fixed::operator++ ( void ) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator-- ( void ) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++ ( int one ) {
	Fixed other;
	other = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (other);
}

Fixed Fixed::operator-- ( int one ) {
	Fixed other;
	other = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (other);
}

bool Fixed::operator==(const Fixed & one){ return (this->_pointValue == one.getRawBits()); }
bool Fixed::operator!=(const Fixed & one){ return (this->_pointValue != one.getRawBits()); }
bool Fixed::operator< (const Fixed & one){ return (this->_pointValue < one.getRawBits()); }
bool Fixed::operator> (const Fixed & one){ return (this->_pointValue > one.getRawBits()); }
bool Fixed::operator<=(const Fixed & one){ return (this->_pointValue <= one.getRawBits()); }
bool Fixed::operator>=(const Fixed & one){ return (this->_pointValue >= one.getRawBits()); }

Fixed & Fixed::min(Fixed & one, Fixed & two){
	return (one.getRawBits() > two.getRawBits() ? two : one);
}

const Fixed & Fixed::min(const Fixed & one, const Fixed & two){
	return (one.getRawBits() > two.getRawBits() ? two : one);
}

Fixed & Fixed::max(Fixed & one, Fixed & two){
	return (one.getRawBits() >= two.getRawBits() ? one : two);
}

const Fixed & Fixed::max(const Fixed & one, const Fixed & two){
	return (one.getRawBits() >= two.getRawBits() ? one : two);
}

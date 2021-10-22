# include <ostream>
#include "Pixel.h"

Pixel::Pixel(unsigned char pixel) : m_pixel(pixel)
{ } // default c-tor
//---------------------------------------------------
Pixel& Pixel::operator|=(const Pixel& p2)
{
	return *this = *this | p2;
}
//------------------------------------------
Pixel& Pixel::operator&=(const Pixel& p2)
{
	return *this = *this & p2;
}
//----------------------------------------------
unsigned char Pixel::getColor() const
{
	return m_pixel;
}
//----------------------------------------------
ostream& operator<<(ostream& os, const Pixel& p)
{
	os << p.getColor();
	return os;
}
//--------------------------------------------------
Pixel operator|(const Pixel& p1, const Pixel& p2)
{ // set the darker pixel if the 2 pixels are not equals (globaly)
	if (p1 == p2)
		return p1;
	return (p1.getColor() > p2.getColor()) ? p1 : p2;
}
//-----------------------------------------------
Pixel operator&(const Pixel& p1, const Pixel& p2)
{ // set the brighter pixel if the 2 pixels are not equals (globaly)
	if (p1 == p2)
		return p1;
	return (p1.getColor() < p2.getColor()) ? p1 : p2;
}
//--------------------------------------
bool operator==(const Pixel& P1, const Pixel& P2)
{ // check if pixels are equals (global)
	return (P1.getColor() == P2.getColor());
}

bool operator!=(const Pixel& p1, const Pixel& p2)
{ // if not equals pixels  (global)
	return !(p1 == p2);
}

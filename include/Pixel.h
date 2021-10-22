#pragma once
#include <iosfwd>
#include "Consts.h"

using std::ostream;


class Pixel
{
public:
	//c-tors
	Pixel(unsigned char pixel = WHITE);

	// public-function
	Pixel& operator|=(const Pixel& p2);
	Pixel& operator&=(const Pixel& p2);

	// get-function
	unsigned char getColor() const;

private:
	unsigned char m_pixel;
};

// global-operator
ostream& operator<<(ostream& os, const Pixel& p);
Pixel operator|(const Pixel& p1, const Pixel& p2);
Pixel operator&(const Pixel& p1, const Pixel& p2);
bool operator==(const Pixel& p1, const Pixel& p2);
bool operator!=(const Pixel& p1, const Pixel& p2);
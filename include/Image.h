#pragma once
# include "Pixel.h"
# include "ImageDataStructure.h"
#include "Consts.h"

class Image
{
public:
	/* c-tors */
	Image();
	Image(int height, int width);
	Image(int height, int width, unsigned char pixel);
	Image(const Image& other);

	/* public-operators */
	Image& operator=(const Image& B);
	Image operator+(const Image& other)const;
	Image& operator+=(const Image& B);
	Image& operator|=(const Image& B);
	Image& operator&=(const Image& B);
	Image& operator*=(const unsigned int n);
	Image operator~()const;
	Pixel& operator()(const unsigned int x, const unsigned int y);
	Pixel operator()(const unsigned int x, const unsigned int y) const;

	/* get-function; */
	int GetHeight()const;
	int GetWidth()const;

private:
	Pixel** m_ThePixelImage;
	ImageDataStructure m_imageStructure;
	int     m_height;
	int     m_width;
};

/* global operators */
ostream& operator<<(ostream& os, const Image& A);
bool operator==(const Image& A, const Image& B);
bool operator!=(const Image& A, const Image& B);
Image operator|(const Image& A, const Image& B);
Image operator&(const Image& A, const Image& B);
Image operator*(const unsigned int n, const Image& A);
Image operator*(const Image& A, const unsigned int n);
#pragma once
# include "Pixel.h"
#include "Consts.h"

class Image;

class ImageDataStructure
{
public:
	/* c_tors */
	ImageDataStructure();
	ImageDataStructure(int row, int col);

	~ImageDataStructure(); //d - tors

/*set-functions */
	Pixel** structureImage();
	void setImageDataStructure(int height, int width);
	void clear();

private:
	Pixel** m_Structure;
	int m_SizeRows;
	void exit_error(); // send errror of allocation and exit program
};

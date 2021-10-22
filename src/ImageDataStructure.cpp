# include <iostream>
#include "ImageDataStructure.h"

ImageDataStructure::ImageDataStructure() : m_SizeRows(0), m_Structure(NULL)
{ } // defaulte c-tor
//--------------------------------------------
ImageDataStructure::ImageDataStructure(int height, int width)
{ // allocate dynamicly with correct size
	m_SizeRows = height;
	m_Structure = new Pixel * [m_SizeRows]; // rows
	if (m_Structure == NULL)
		exit_error();

	for (int i = 0; i < m_SizeRows; i++)
	{
		m_Structure[i] = new Pixel[width]; // cols
		if (m_Structure[i] == NULL)
			exit_error();
	}
}
//------------------------------------------------------------------
ImageDataStructure::~ImageDataStructure()
{
	for (int row = 0; row < m_SizeRows - 1; row++)
		delete m_Structure[row];
	delete[] m_Structure;
	m_Structure = NULL;
}
//------------------------------------------------------------
void ImageDataStructure::setImageDataStructure(int height, int width)
{   // // allocate dynamicly with correct size
	clear(); // clear memory
	m_SizeRows = height;
	m_Structure = new Pixel * [m_SizeRows]; // rows
	if (m_Structure == NULL)
		exit_error();

	for (int i = 0; i < m_SizeRows; i++)
	{
		m_Structure[i] = new Pixel[width]; // cols
		if (m_Structure[i] == NULL)
			exit_error();
	}
}
//---------------------------------------------------
Pixel** ImageDataStructure::structureImage()
{ // return pointer (**)
	return this->m_Structure;
}
//--------------------------------------------------
void ImageDataStructure::clear()
{ // clear memory
	for (size_t i = 0; i < m_SizeRows; i++)
		delete m_Structure[i];
	delete[] m_Structure;
	m_Structure = NULL;
	m_SizeRows = 0;
}
//----------------------------------------------------
void ImageDataStructure::exit_error()
{ // if fail allocaition
	std::cerr << "Cannot allocate memory\n";
	exit(EXIT_FAILURE);
}



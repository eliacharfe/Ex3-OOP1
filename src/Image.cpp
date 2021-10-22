# include <ostream>
# include "Image.h"

Image::Image() : m_height(0), m_width(0), m_ThePixelImage(NULL)
{ } // default
//------------------------------------------------------
Image::Image(int height, int width)
{ // c-tor
	m_height = height;
	m_width = width;
	m_imageStructure.setImageDataStructure(m_height, width);
	m_ThePixelImage = m_imageStructure.structureImage();
}
//-------------------------------------------------------
Image::Image(int height, int width, unsigned char pixel)
{ // c-tor
	*this = Image(height, width);//using c-tor: get the right size
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			m_ThePixelImage[i][j] = pixel; // insert pixel
}
//-------------------------------------------------------
Image::Image(const Image& other)
{ // copy constractor
	*this = Image(other.GetHeight(), other.GetWidth());//using c-tor:
	for (int i = 0; i < GetHeight(); i++)
		for (int j = 0; j < GetWidth(); j++)
			m_ThePixelImage[i][j] = other(i, j);//copy pixels
}
//-------------------------------------------------
Image& Image::operator=(const Image& B)
{
	if (this == &B)// check addresses
		return *this;

	m_height = B.GetHeight();
	m_width = B.GetWidth();

	m_imageStructure.setImageDataStructure(m_height, m_width);//build new
	m_ThePixelImage = m_imageStructure.structureImage();// update pointer (**)

	for (int i = 0; i < B.GetHeight(); i++)
		for (int j = 0; j < B.GetWidth(); j++)
			m_ThePixelImage[i][j] = B(i, j);// reuse of = from Pixel

	return *this;
}
//-------------------------------------------------------
Image Image::operator+(const Image& other) const
{ // image + image2
	int maxRow = other.GetHeight() >= this->GetHeight() ?
		other.GetHeight() : this->GetHeight();//save the max height
	int sumCol = other.GetWidth() + this->GetWidth();// width A + width B

	Image temp(maxRow, sumCol);//make tmp using copy c-tor with right size

	for (int i = 0; i < m_height; i++) //copy the left image
		for (int j = 0; j < this->GetWidth(); j++)
			temp(i, j) = m_ThePixelImage[i][j];//insert pixels

	for (int i = 0; i < other.m_height; i++)
		for (int j = 0; j < other.m_width; j++)
			temp(i, j + m_width) = other(i, j);//insert pixels

	return temp;
}
//---------------------------------------------------------------
Image& Image::operator+=(const Image& B)
{// reuse
	return *this = *this + B;
}
//------------------------------------------------
Image& Image::operator|=(const Image& B)
{ // reuse
	return *this = *this | B;
}
//--------------------------------------------
Image& Image::operator&=(const Image& B)
{ // reuse
	return *this = *this & B;
}
//---------------------------------------------------
Image& Image::operator*=(const unsigned int n)
{ // reuse
	return *this = *this * n;
}
//-----------------------------------------------------------
Image Image::operator~()const
{ // return negative
	Image temp(*this); //make a copy (using copy c-tor) of the curr image
	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
		{
			if (temp(i, j) == BLACK) // like it sounds
				temp(i, j) = WHITE;
			else if (temp(i, j) == WHITE)
				temp(i, j) = BLACK;
		}
	return temp;
}
//--------------------------------------------------------------------
Pixel& Image::operator()(const unsigned int x, const unsigned int y)
{ // change pixel in x, y posisition
	return m_ThePixelImage[x][y];
}
//------------------------------------------------------------------
Pixel Image::operator()(const unsigned int x, const unsigned int y) const
{ // return the pixel at x, y posiotion 
	return m_ThePixelImage[x][y];
}
//--------------------------------------------------------------
int Image::GetHeight() const
{
	return m_height;
}
//------------------------------------------------------------
int Image::GetWidth() const
{
	return m_width;
}
//---------------------------------------------------------------
ostream& operator<<(ostream& os, const Image& A)
{ // print image
	for (int i = 0; i < A.GetHeight(); i++)
	{
		for (int j = 0; j < A.GetWidth(); j++)
			os << A(i, j);
		os << std::endl;
	}
	return os;
}
//------------------------------------------------------------------
bool operator==(const Image& left, const Image& right)
{ // check sizes and each pixels of both are equals, return true if equals  (global)
	if (left.GetHeight() != right.GetHeight())
		return false;
	if (left.GetWidth() != right.GetWidth())
		return false;
	for (int row = 0; row < left.GetHeight(); row++)
		for (int col = 0; col < left.GetWidth(); col++)
			if (left(row, col) != right(row, col))
				return false;
	return true; // if right equals left
}
//--------------------------------------------------------
bool operator!=(const Image& A, const Image& B)
{ // return true if 2 images are not equals  (global)
	return !(A == B);
}
//------------------------------------------------------
Image operator|(const Image& A, const Image& B)
{ // compare pixels 1 by 1 of both images and set the darker pixel  (global)
	int max_tmpH = (A.GetHeight() > B.GetHeight()) ? A.GetHeight() : B.GetHeight();
	int max_tmpW = (A.GetWidth() > B.GetWidth()) ? A.GetWidth() : B.GetWidth();

	int min_tmpH = (A.GetHeight() < B.GetHeight()) ? A.GetHeight() : B.GetHeight();
	int min_tmpW = (A.GetWidth() < B.GetWidth()) ? A.GetWidth() : B.GetWidth();
	Image temp(max_tmpH, max_tmpW);

	for (int row = 0; row < A.GetHeight(); row++) 	//A
		for (int col = 0; col < A.GetWidth(); col++)
			temp(row, col) = A(row, col);

	for (int row = 0; row < B.GetHeight(); row++) 	//B
	{
		for (int col = 0; col < B.GetWidth(); col++)
		{
			if ((row < min_tmpH) && (col < min_tmpW)) // if is inside the 2 images
				temp(row, col) = A(row, col) | B(row, col);// set darker
			else
				temp(row, col) = B(row, col); // only in B
		}
	}
	return temp;
}
//-------------------------------------------------
Image operator&(const Image& A, const Image& B)
{ // compare pixels 1 by 1 of both images and set the brighter pixel  (global)
	int min_tmpH = (A.GetHeight() < B.GetHeight()) ? A.GetHeight() : B.GetHeight();
	int min_tmpW = (A.GetWidth() < B.GetWidth()) ? A.GetWidth() : B.GetWidth();

	Image temp(min_tmpH, min_tmpW);

	for (int row = 0; row < min_tmpH; row++)
	{
		for (int col = 0; col < min_tmpW; col++)
			temp(row, col) = A(row, col) & B(row, col);//set brighter
	}
	return temp;
}
//-------------------------------------------------
Image operator*(const unsigned int mul, const Image& A)
{ // multiply from left  (global)
	Image tmp;
	if (mul > 0)
	{
		for (unsigned int i = 0; i < mul; i++)
			tmp += A; // reuse
	}
	return tmp;
}
//-----------------------------------------
Image operator*(const Image& A, const unsigned int mul)
{// multiply from right  (global)
	Image tmp;
	if (mul > 0)
	{
		for (unsigned int i = 0; i < mul; i++)
			tmp += A; // reuse
	}
	return tmp;
}
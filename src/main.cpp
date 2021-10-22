// OOP_ex03.cpp : Defines the entry point for the application.
//
#include "Pixel.h"
#include "Image.h"
#include "Consts.h"
#include <iostream>

using std::cout;
using std::endl;

#define PokeBall 1
# define Pixel_test 1
# define Image_test 1
# define our_test 1

int main()
{
#if PokeBall 
	std::cout << Image(19, 2, BLACK) +

		((Image(5, 2, BLACK) | Image(13, 1, WHITE) |
			~(Image(19, 2, WHITE) | Image(13, 2, BLACK)))) +

		(Image(4, 2, BLACK) | ~(Image(5, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~((((~((Image(19, 2, WHITE)) |
				Image(15, 2, BLACK)))) | Image(12, 2, GRAY)) |
				Image(11, 2, BLACK)))))) +

		(Image(3, 2, BLACK) | ~(Image(4, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(12, 2, BLACK) |
				(Image(14, 2, GRAY) | ~(Image(16, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(2, 2, BLACK) | ~(Image(3, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(13, 2, BLACK) |
				(Image(15, 2, GRAY) | ~(Image(17, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (Image(4, 2, GRAY) |
			~((Image(6, 2, BLACK) | ~(~(Image(9, 2, GRAY) |
				~(Image(10, 2, BLACK) | ~(Image(14, 2, BLACK) |
					(Image(16, 2, GRAY) | ~(Image(18, 2, BLACK) |
						~Image(19, 2, BLACK)))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (Image(3, 2, GRAY) |
			~((Image(5, 2, BLACK) | ~(~(Image(8, 2, GRAY) |
				~(Image(11, 2, BLACK) | ~(Image(15, 2, BLACK) |
					(Image(17, 2, GRAY) | ~(Image(18, 2, BLACK) |
						~Image(19, 2, BLACK)))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (Image(3, 2, GRAY) |
			~((Image(4, 2, BLACK) | ~(~(Image(7, 2, GRAY) |
				~(Image(8, 2, BLACK) | ~(Image(11, 2, BLACK) |
					~(Image(12, 2, BLACK) | ~(Image(16, 2, BLACK) |
						(Image(17, 2, GRAY) | ~(Image(18, 2, BLACK) |
							~Image(19, 2, BLACK)))))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (~(Image(7, 2, GRAY) |
			~(Image(8, 2, BLACK) | ~(Image(9, 2, BLACK)
				| ~(Image(10, 2, GRAY) | ~(Image(11, 2, BLACK) |
					~(Image(12, 2, BLACK) | ~(Image(17, 2, BLACK)
						| ~(Image(18, 2, BLACK) |
							~Image(19, 2, BLACK)))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (~(Image(7, 2, GRAY) |
			~(Image(8, 2, BLACK) | ~(Image(11, 2, BLACK) |
				~(Image(12, 2, BLACK) | ~(Image(17, 2, BLACK) |
					~(Image(18, 2, BLACK) | ~Image(19, 2, BLACK)))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (~(Image(8, 2, GRAY) |
			~(Image(11, 2, BLACK) | ~(Image(17, 2, BLACK) |
				~(Image(18, 2, BLACK) | ~Image(19, 2, BLACK)))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(16, 2, BLACK) |
				(~(Image(18, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(2, 2, BLACK) | ~(Image(3, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(15, 2, BLACK) |
				(~(Image(17, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(3, 2, BLACK) | ~(Image(4, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(14, 2, BLACK) |
				(~(Image(16, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(4, 2, BLACK) | ~(Image(5, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(12, 2, BLACK) |
				(~(Image(15, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		((Image(5, 2, BLACK) | Image(13, 1, WHITE) |
			~(Image(19, 2, WHITE) | Image(13, 2, BLACK)))) +

		Image(19, 2, BLACK);
#endif

#if Pixel_test

	cout << "  c-tors" << endl;
	Pixel p1(BLACK);
	Pixel p2(GRAY);
	Pixel p3(WHITE);
	Pixel p4;
	Pixel test1;
	Pixel test2;
	//-----------------------------------------
	cout << "  Black   p1: " << p1 << endl;
	cout << "  grey    p2: " << p2 << endl;
	cout << "  white   p3: " << p3 << endl;
	cout << "  default p4: " << p4 << endl;
	cout << endl << endl;
	//-----------------------------------------

	cout << "  p1==p1" << endl;
	if (p1 == p1)
		cout << "  good" << endl;

	cout << "  p1==p2" << endl;
	if (p1 == p2)
		cout << "  bad" << endl;
	else
		cout << "  good" << endl;

	cout << "  p1!=p2" << endl;
	if (p1 != p2)
		cout << "  good" << endl;

	cout << "  p1!=p1" << endl;
	if (p1 != p1)
		cout << "  bad" << endl;
	else
		cout << "  good" << endl;

	test1 = p1 | p1;
	cout << "  test1 = p1|p1 " << test1 << endl;
	test1 = p1 | p2;
	cout << "  test1 = p1|p2 " << test1 << endl;
	test1 = p2 | p1;
	cout << "  test1 = p2|p1 " << test1 << endl;
	test1 = p3 | p1;
	cout << "  test1 = p3|p1 " << test1 << endl;
	test2 |= p1;
	cout << "  test2 |= p1   " << test2 << endl;

	test1 = p3;
	test2 = p3;
	cout << "  test1 white " << (test1) << endl;
	cout << "  test2 white " << (test2) << endl;

	test2 = p1 & p1;
	cout << "  test2 = p1&p1 " << test2 << endl;
	test2 = p1 & p2;
	cout << "  test2 = p1&p2 " << test2 << endl;
	test2 = p2 & p1;
	cout << "  test2 = p2&p1 " << test2 << endl;
	test2 = p3 & p1;
	cout << "  test2 = p3&p1 " << test2 << endl;
	test1 &= p1;
	cout << "  test1 &= p1   " << test1 << endl;
	cout << endl << endl;

#endif // Pixel_test


#if Image_test

	Image im1(15, 6);
	cout << im1;

	Image im2(10, 10, GRAY);
	cout << im2;

	Image im3(7, 8, BLACK);
	cout << im3;

	Image im4(im1);
	cout << im4;


	if (im1 == im2)
		cout << endl << " im1 == im2 " << "  bad" << endl;

	else
		cout << endl << " im1 == im2 " << "  good" << endl;

	if (im1 == im4)
		cout << endl << " im1 == im4 " << "  good" << endl;

	else
		cout << endl << " im1 == im2 " << endl << "  bad" << endl;


	Image im5(6, 6, GRAY);
	Image im6(4, 4);
	cout << endl << im5 << endl << im6 << endl;
	im6 = im5;
	cout << endl << im5 << endl << im6 << endl;
	Image im7;
	im7 = im1 + im2;
	cout << endl << " im7 = im1 + im2  " << endl;
	cout << im7 << endl;


	Image im8(9, 11);
	Image img9(5, 15, GRAY);
	Image img10(15, 5, BLACK);
	im8 = img9 | img10;
	cout << endl << "  im8 = img9 | img10  " << endl << im8 << endl;

	Image im14(5, 15, BLACK);
	Image img15(15, 5, GRAY);
	im14 |= img15;
	cout << endl << "  im14 |= im15  " << endl << im14 << endl;


	Image im30(9, 11, BLACK);
	Image img31(15, 12, WHITE);
	im30 = ~img31;
	cout << endl << "  im30 = ~img31  " << endl << im30 << endl;


	Image s(4, 6, BLACK);
	Image t(2, 8, GRAY);
	Image o(10, 10, WHITE);
	o = s | t;
	cout << im3 << endl;
	s |= t;
	cout << s << endl;


	Image d(9, 11);
	Image e(5, 15, GRAY);
	Image f(15, 5, BLACK);
	d = e & f;
	cout << endl << "  d = e & f  " << endl << d << endl;


	Image ddd(15, 5, BLACK);
	Image qqq(5, 15, GRAY);
	cout << "ddd: \n";
	cout << ddd << endl << endl;
	cout << "qqq: \n";
	cout << qqq << endl << endl;
	ddd &= qqq;
	cout << "ddd &= qqq: \n" << ddd << endl;


	Image i(3, 4, BLACK);
	cout << endl << "  i " << endl << i << endl;
	Image j(5, 2, GRAY);
	cout << endl << "  j " << endl << j << endl;


	Image img12(5, 15, GRAY);
	//img12
	cout << endl << "  im12 " << endl << img12 << endl;
	Image img13(15, 5, BLACK);
	Image x = img12 & img13;
	cout << endl << "  im11 = img12 & img13  " << endl << x << endl;

	unsigned n = 3;
	Image k(10, 13 , GRAY);
	n++;
	cout << "k is : " << endl << k << endl;
	k *= n;
	cout << "k*=n: " << endl << k << endl;


	Image im20(9, 11, BLACK);
	Image img21(5, 15, GRAY);
	im20 += img21;
	cout << endl << "  im20 += im21  " << endl << im20 << endl;
	Image im40(15, 5, BLACK);
	Image im41(5, 15, GRAY);

	cout << "im40: \n";
	cout << im40 << endl << endl;
	cout << "im41: \n";
	cout << im41 << endl << endl;
	im40 += im41;
	cout << "im40 += im41: \n" << im40 << endl;

	Image fff = im20 & im40;
	cout << endl << fff << endl;


	// ex3.cpp : Defines the entry point for the application.
//
#endif
#if our_test
	using namespace std;

	//int main()
	{
		// TESTS
			// TESTING Pixel
		cout << "TESTING Pixel:\n";
		const auto p1 = Pixel();
		const auto p2 = Pixel(176);
		auto p3 = Pixel(219);

		if (p1 != p2)
			cout << "Test1 passed!\n";
		else
			cout << "Test1 FAILED...\n";
		if ((p1 & p2) == p1) // FAILED
			cout << "Test2 passed!\n";
		else
			cout << "Test2 FAILED...\n";

		if ((p1 | p2) == p2) // FAILED
			cout << "Test3 passed!\n";
		else
			cout << "Test3 FAILED...\n";

		p3 &= p1;

		if (p3 == p1)
			cout << "Test4 passed!\n";
		else
			cout << "Test4 FAILED...\n";

		p3 |= p2;

		if (p3 == p2)
			cout << "Test5 passed!\n";
		else
			cout << "Test5 FAILED...\n";

		// TESTTING IMAGE
		cout << "TESTING Image:\n";

		const auto img1 = Image(5, 2);

		const auto img2 = Image(2, 5);

		if (img1.GetHeight() == 5)
			cout << "Test6 passed!\n";
		else
			cout << "Test6 FAILED...\n";

		if (img1.GetWidth() == 2)
			cout << "Test7 passed!\n";
		else
			cout << "Test7 FAILED...\n";

		if ((img1 + img1).GetHeight() == 5)
			cout << "Test8 passed!\n";
		else
			cout << "Test8 FAILED...\n";

		if ((img1 + img1).GetHeight() == 5)
			cout << "Test9 passed!\n";
		else
			cout << "Test9 FAILED...\n";

		Image img3 = img1;
		if (img3 == img1) // FAILED
			cout << "Test10 passed!\n";
		else
			cout << "Test10 FAILED...\n";

		const auto img4 = Image();
		const auto img5 = Image(2, 5);

		if (img4.GetHeight() == 0)
			cout << "Test11 passed!\n";
		else
			cout << "Test11 FAILED...\n";

		if (img4.GetWidth() == 0)
			cout << "Test12 passed!\n";
		else
			cout << "Test12 FAILED...\n";

		if ((img4 + img5).GetWidth() == 5)
			cout << "Test13 passed!\n";
		else
			cout << "Test13 FAILED...\n";

		// TESTTING LIRON
		cout << "TESTING Liron:\n";
		if (img1 + img2 + img3 + img4 == (img1 + img2) + (img3 + img4))
			cout << "Test14 passed!\n";
		else
			cout << "Test14 FAILED...\n";

		return 0;
	}


#endif // Image_test


	return 0;
}




#include "image_format.h"
#include <cmath>


void line(int ax, int ay, int bx, int by, Image& framebuffer, Color& color ) {
	// paint a line by its parametric eq
	float t;
	int y;

	// if line steep , transpose image
	bool steep = std::abs(ax-bx) < std::abs(ay-by);
	if (steep) {
		std::swap(ax,ay);
		std::swap(bx,by);
	}

	// if a comes after b, swap
	if (ax>bx) {
		std::swap(ax, bx);
		std::swap(ay, by);
	}

	for (int x = ax; x <= bx; ++x) {
		t = (x-ax) / static_cast<float>(bx-ax);
		y = std::round(ay + (by-ay)* t);
		if (steep)
			// detranspose
			framebuffer.set(y,x, color);
		else
			framebuffer.set(x, y, color);
	}

}
	








#include "image_format.h"
#include <cmath>
// #include <iostream>



Color white = {255, 255, 255, 255};
Color green = {0, 255, 0, 255};
Color red = {0, 0, 255, 255};
Color blue = {255, 0, 0, 255};


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
	

int main(int argc, char** argv) {
	int width = 128;
	int height = 128;

	Image framebuffer(width, height, 3); // 3 vals rgb for the frame

	// put the points
	int ax =  7, ay =  3;
	int bx = 12, by = 37;
	int cx = 62, cy = 53;

	line(ax, ay, bx, by, framebuffer, blue);
	line(cx, cy, bx, by, framebuffer, green);
	line(cx, cy, ax, ay, framebuffer, white);
	line(ax, ay, cx, cy, framebuffer, red);	

	// write to file 
	framebuffer.write_file("framebuffer.tga");



	return 0;
}








#include "image_format.h"
// #include <iostream>



Color white = {255, 255, 255, 255};
Color green = {0, 255, 0, 255};
Color red = {0, 0, 255, 255};
Color blue = {255, 0, 0, 255};


void line(int ax, int ay, int bx, int by, Image& framebuffer, Color& color ) {
	// paint a line by its parametric eq
	int x_t;
	int y_t;

	for (float t =0.0 ; t < 1.0; t+=0.02) {
		x_t = ax + t * (bx - ax);
		y_t = ay + t * (by - ay);
		framebuffer.set(x_t, y_t, color);
	}
}
	

int main(int argc, char** argv) {
	int width = 128;
	int height = 128;

	Image framebuffer(width, height, 3); // 3 vals rgb for the frame

	// put the points
	int ax  = 7, ay = 20;
	int bx  = 17, by = 30;
	int cx  = 37, cy = 40;

	line(ax, ay, cx, cy, framebuffer, red);
	
	framebuffer.set(ax, ay, red);
	framebuffer.set(bx, by, green);
	framebuffer.set(cx, cy, blue);
	

	// write to file 
	framebuffer.write_file("framebuffer.tga");



	return 0;
}

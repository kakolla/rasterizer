






#include "image_format.h"
// #include <iostream>



Color white = {255, 255, 255, 255};
Color green = {0, 255, 0, 255};
Color red = {0, 0, 255, 255};
Color blue = {255, 0, 0, 255};



int main(int argc, char** argv) {
	int width = 128;
	int height = 128;

	Image framebuffer(width, height, 3); // 3 vals rgb for the frame

	// put the points
	int ax  = 7, ay = 20;
	int bx  = 17, by = 30;
	int cx  = 37, cy = 40;
	
	framebuffer.set(ax, ay, red);
	framebuffer.set(bx, by, green);
	framebuffer.set(cx, cy, blue);
	

	// write to file 
	framebuffer.write_file("framebuffer.tga");



	return 0;
}

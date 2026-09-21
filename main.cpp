






#include "image_format.h"



Color white = {255, 255, 255, 255};
Color green = {0, 255, 0, 255};
Color red = {0, 0, 255, 255};
Color blue = {255, 0, 0, 255};


extern void line(int ax, int ay, int bx, int by, Image& framebuffer, Color& color );


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

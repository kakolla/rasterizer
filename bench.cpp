





#include "image_format.h"
#include <random>


Color white = {255, 255, 255, 255};
Color green = {0, 255, 0, 255};
Color red = {0, 0, 255, 255};
Color blue = {255, 0, 0, 255};


extern void line(int ax, int ay, int bx, int by, Image& framebuffer, Color& color );


int main(int argc, char** argv) {

	int width = 128;
	int height = 128;

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> distributoin(0, 127);
	std::uniform_int_distribution<int> color(0, 2);



	int reps = 100000;

	Image framebuffer(width, height, 3); // 3 vals rgb for the frame

	// put the points
	int ax, bx;
	int ay, by;
	Color colors[] = {red, green, blue};
	int colornum;

	for (int i = 0; i < reps; ++i){
		ax = distributoin(gen);
		bx = distributoin(gen);
		by = distributoin(gen);
		ay = distributoin(gen);
		colornum = color(gen);

		line(ax, ay, bx, by, framebuffer, colors[colornum]);

	}

	// write to file 
	framebuffer.write_file("framebuffer.tga");



	return 0;
}






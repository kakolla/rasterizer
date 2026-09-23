






#include "image_format.h"
#include <string>
#include "model.h"



Color white = {255, 255, 255, 255};
Color green = {0, 255, 0, 255};
// Color red = {0, 0, 255, 255};
Color blue = {255, 0, 0, 255};


extern void line(int ax, int ay, int bx, int by, Image& framebuffer, Color& color );

extern const int width = 768;
extern const int height = 1024;


int main(int argc, char** argv) {
	Image framebuffer(width, height, 3); // 3 vals rgb for the frame

	// read file
	Model m("obj/diablo3_pose.obj");
	m.write_to_file(framebuffer);


	


	return 0;
}

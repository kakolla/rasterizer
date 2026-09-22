






#include "image_format.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>



Color white = {255, 255, 255, 255};
Color green = {0, 255, 0, 255};
Color red = {0, 0, 255, 255};
Color blue = {255, 0, 0, 255};


extern void line(int ax, int ay, int bx, int by, Image& framebuffer, Color& color );


int main(int argc, char** argv) {
	int width = 512;
	int height = 512;

	Image framebuffer(width, height, 3); // 3 vals rgb for the frame

	// read file
	std::ifstream ofile("obj/diablo3_pose.obj");
	if (!ofile) {
		std::cout << "error reading file" << std::endl;
		exit(-1);
	}
	std::string total_line;
	char type;
	float x, y, z;
	std::vector<std::tuple<float, float, float>> pts;

	float smallest_x = 999., smallest_y = 999., largest_x = -999. , largest_y = -999.;
	int a, b, c; // connecting pts of a triangle
	int temp;
	char t;

	std::vector<std::tuple<int, int>> edges;


	while (std::getline(ofile, total_line)) {
		std::stringstream ss(total_line);
		ss >> type;
		if (type == 'v') {
			// v 0.119952 0.67202 0.101202
			ss >> x >> y >> z;
			pts.push_back(std::make_tuple(x,y,z));
			smallest_x = std::min(smallest_x, x);
			smallest_y = std::min(smallest_y, y);
			largest_x = std::max(largest_x, x);
			largest_y = std::max(largest_y, y);

		} else if (type == 'f') {
			// f 47/47/47 40/40/40 45/45/45
			// get the indices only 47,40,45
			ss >> a >>t >> temp >> t >> temp
				>> b >> t >> temp >> t >> temp
				>> c;
			edges.push_back(std::make_tuple(a, b));
			edges.push_back(std::make_tuple(b, c));
			edges.push_back(std::make_tuple(a, c));

			// std::cout << "parsed: " << a << " " << b << " " << c << std::endl;
		}

	}


	
	// shift to 0,0 and normalize
	float rangex = largest_x - smallest_x;
	float rangey = largest_y - smallest_y;
	if (!rangex) rangex = 1;
	if (!rangey) rangey = 1;

	for (auto& [x,y,_] : pts) {
		x = ((x - smallest_x) / rangex) * width;
		y = ((y - smallest_y) / rangey) * height;
		// std::cout << x << " " << y << std::endl;
		// exit(0);
	}
	// std::cout << "abi" << std::endl;
	// std::cout << std::get<0>(pts[0]) << std::endl;

	for (auto& [e1, e2] : edges) {
		// the line e1 to e2
		int ax = std::get<0>(pts[e1-1]);
		int ay = std::get<1>(pts[e1-1]);

		int bx = std::get<0>(pts[e2-1]);
		int by = std::get<1>(pts[e2-1]);
		// std::cout << "drawing a line from"  << ax << " " << ay << " to " << bx << " " << by << std::endl;
		line(ax, ay, bx, by, framebuffer, blue);
	}


	// write to file 
	framebuffer.write_file("framebuffer.tga");
	std::cout << "Wrote to file framebuffer.tga" << std::endl;



	return 0;
}

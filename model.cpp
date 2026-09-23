


#include "model.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "image_format.h"


extern int height;
extern int width;


extern void line(int ax, int ay, int bx, int by, Image& framebuffer, Color& color );





Color red = {0, 0, 255, 255};
Model::Model(std::string file_name) {
	// "obj/diablo3_pose.obj"
	std::ifstream ofile(file_name);
	if (!ofile) {
		std::cout << "error reading file" << std::endl;
		exit(-1);
	}


	std::string total_line;
	char type;
	float x, y, z;
	// std::vector<std::tuple<float, float, float>> pts;

	
	smallest_x = 999., smallest_y = 999., largest_x = -999. , largest_y = -999.;
	int a, b, c; // connecting pts of a triangle
	int temp;
	char t;



	// read ofile and push to points and edges
	while (std::getline(ofile, total_line)) {
		std::stringstream ss(total_line);
		ss >> type;
		if (type == 'v') {
			// v 0.119952 0.67202 0.101202
			ss >> x >> y >> z;
			pts.push_back({x,y,z});
			// pts.push_back(std::make_tuple(x,y,z));
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




}


std::pair<int, int> Model::project(vec3 v) {
	return {
		(v.x + 1.0) * width/2,
		(v.y + 1.0) * height/2
	};
}


void Model::write_to_file(Image& framebuffer, std::string ofile_name) {
	// shift to 0,0 and normalize
	float rangex = largest_x - smallest_x;
	float rangey = largest_y - smallest_y;
	if (!rangex) rangex = 1;
	if (!rangey) rangey = 1;

	// for (auto& [x,y,_] : pts) {
	// 	x = ((x - smallest_x) / rangex) * width;
	// 	y = ((y - smallest_y) / rangey) * height;
	// 	// std::cout << x << " " << y << std::endl;
	// 	// exit(0);
	// }

	
	// std::cout << "abi" << std::endl;
	// std::cout << std::get<0>(pts[0]) << std::endl;

	for (auto& [e1, e2] : edges) {
		// the line e1 to e2
		auto [ax,ay] = project(pts[e1-1]);
		// int ax = pts[e1-1].x;
		// int ay = pts[e1-1].y;
		auto [bx,by] = project(pts[e2-1]);

		// int bx = pts[e2-1].x;
		// int by = pts[e2-1].y;
		// std::cout << "drawing a line from"  << ax << " " << ay << " to " << bx << " " << by << std::endl;
		line(ax, ay, bx, by, framebuffer, red);
	}


	// write to file 
	framebuffer.write_file(ofile_name);
	std::cout << "Wrote to file " << ofile_name << std::endl;





}







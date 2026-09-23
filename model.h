#pragma once





#include <string>
#include <tuple>
#include <vector>
#include "image_format.h"



struct vec3 {
	float x;
	float y;
	float z;
};




class Model {

public:


	
	float smallest_x;
	float smallest_y; 
	float largest_x; 
	float largest_y;

	// build model
	Model(std::string file_name);


	// void write_to_file(std::string ofile_name);

	// void write_to_file(Image& frame_buffer, std::string ofile_name);

	void write_to_file(Image& framebuffer, std::string ofile_name = "framebuffer.tga");
	
	
	std::pair<int, int> project(vec3 v); // proj onto xy


	std::vector<vec3> pts;
	std::vector<std::tuple<int,int>> edges; // point to anohter point, ubt its the index



};







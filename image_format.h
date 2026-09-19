#pragma once
#include <vector>
#include <cstdint>



struct Image {

	int height() const;
	int width() const;


	Image() =  default;

	Image(const int w, const int h, const int bpp);

private:
	int h;
	int w;
	int bytes_per_pixel;

	// actual dat of image
	std::vector<uint8_t> pixels;

};



struct Color {
	//  blue green red alpha
	std::uint8_t bgra[4] = {0,0,0,0};
	std::uint8_t bytes_per_pixel = 4;
	
	// overload for getting the color/alpha
	std::uint8_t& operator[](const std::uint8_t i ) {
		return bgra[i];
	}

};

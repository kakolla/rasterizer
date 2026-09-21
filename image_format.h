#pragma once
#include <vector>
#include <cstdint>
#include <string>
#include <cstring>




struct Color {
	//  blue green red alpha
	std::uint8_t bgra[4] = {0,0,0,0};
	std::uint8_t bytes_per_pixel = 4;
	
	// overload for getting the color/alpha
	std::uint8_t& operator[](const std::uint8_t i ) {
		return bgra[i];
	}

};


struct Image {

	int height() const;
	int width() const;


	Image() =  default;

	Image(const int w, const int h, const int bpp);

	// set a pixel
	// inline void set(const int x, const int y, Color& color);

	inline void set(const int x, const int y, Color& color) {
		// set color
		if (!pixels.size() || x < 0 || y < 0 || x >= w || y >= h) return;

		int pixel_index = y * w + x;
		int offsetbytes = pixel_index * bytes_per_pixel;

		
		// move the color value into the pixel's offset
		memcpy(pixels.data() + offsetbytes, color.bgra, bytes_per_pixel);//

	}

	// write to file
	void write_file(const std::string filename) const;

private:
	int h;
	int w;
	int bytes_per_pixel;

	// actual dat of image
	std::vector<uint8_t> pixels;

};



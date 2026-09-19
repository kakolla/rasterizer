



#include "image_format.h"
#include <fstream>
#include <cstring>





int Image::height() const {
	return this->h;
}

int Image::width() const {
	return this->w;
}


// main ctor
Image::Image(const int w, const int h, const int bpp) : w(w), h(h), bytes_per_pixel(bpp), pixels(w*h*bpp, 0) {}



void Image::set(const int x, const int y, Color& color) {
	// set color
	if (!pixels.size() || x < 0 || y < 0 || x >= w || y >= h) return;

	int pixel_index = y * w + x;
	int offsetbytes = pixel_index * bytes_per_pixel;

	
	// move the color value into the pixel's offset
	memcpy(pixels.data() + offsetbytes, color.bgra, bytes_per_pixel);//

}


// write the file
void Image::write_file(const std::string filename) const {
	// tga type header - just tga specific shenanigans
	std::ofstream ofile(filename, std::ios::binary); // binary mode

	if (!ofile) return;


	// header is 18 byts
	std::uint8_t header[18] = {};

	header[2] = 2;
	header[12] = w & 0xFF;
	header[13] = (w >> 8) & 0xFF;
	header[14] = h & 0xFF;
	header[15] = (h >> 8) & 0xFF;
	header[16] = bytes_per_pixel * 8;// bits
	header[17] = 0x20; // top left image origin

	ofile.write(reinterpret_cast<const char*>(header), 18);

	// write pixels
	ofile.write(
			reinterpret_cast<const char*>(pixels.data()),
			pixels.size()

			);
	

	


}










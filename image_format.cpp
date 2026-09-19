



#include "image_format.h"
// #include <iostream>





int Image::height() const {
	return this->h;
}

int Image::width() const {
	return this->w;
}


// main ctor
Image::Image(const int w, const int h, const int bpp) : w(w), h(h), bytes_per_pixel(bpp), pixels(w*h*bpp, 0) {}











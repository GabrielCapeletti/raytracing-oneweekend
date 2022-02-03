#ifndef RTOW_UTILS_H
#define RTOW_UTILS_H

#include "vector3.h"

namespace rayt
{
	//Saving rendered image to file for now	
	extern const char* FILE_NAME;
	
	void write_pixel_to_img(std::uint8_t* img, int index, const color pixel);
	void save_jpg(const int width, const int height, const int no_channels, unsigned char* img);
	
}

#endif

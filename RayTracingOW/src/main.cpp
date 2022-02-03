/**
* Temporary class to render one frame and save it somewhere.
* This will get removed once the ray tracer is finished and we hook it up to a window
*/

#include <iostream>
#include <string>
#include "../include/utils.h"

typedef rayt::color color;

int main()
{
	const int IMAGE_WIDTH = 256;
	const int IMAGE_HEIGHT = 256;

	auto* img = new uint8_t[IMAGE_HEIGHT * IMAGE_WIDTH * 3];
	
	for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
	{		
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		
		for (int i = 0; i < IMAGE_WIDTH; ++i) 
		{
			auto pixel = color(static_cast<float>(i) / (IMAGE_WIDTH - 1),
			                   static_cast<float>(j) / (IMAGE_HEIGHT - 1),
			                   0.25);			

			pixel *= 255.999f;
			const auto inverted_j = IMAGE_HEIGHT - j - 1;
			const auto index = (inverted_j * IMAGE_WIDTH * 3) + i * 3;
			
			write_pixel_to_img(img, index, pixel);						
		}	
	}

	rayt::save_jpg(IMAGE_WIDTH, IMAGE_HEIGHT, 3, img);
	std::cerr << "\nDone.\n";

	return 0;
}

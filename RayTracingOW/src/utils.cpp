#include "../include/vector3.h"
#include "../include/stb_image/stb_image_write.h"

namespace rayt
{
	const char* FILE_NAME = "result42.jpg";
	
	void write_pixel_to_img(std::uint8_t* img, int index, const color pixel)
	{
		img[index] = static_cast<uint8_t>(pixel.x());
		img[++index] = static_cast<uint8_t>(pixel.y());
		img[++index] = static_cast<uint8_t>(pixel.z());
	}

	void save_jpg(const int width, const int height, const int no_channels, unsigned char* img)
	{	
		stbi_write_jpg(FILE_NAME, width, height, no_channels, img, 100);
	}
}


#include "ProductList.h"

std::string image_type(std::string file_name)
{
	//https://stackoverflow.com/questions/347949/how-to-convert-a-stdstd::string-to-const-char-or-char 
	const char * c = file_name.c_str();
	FILE* fp = fopen(c, "rb");

  std::string directory = "./output/converted_image.jpg";

  Magick::Image image_in;
	image_in.read(file_name);

	if (fp == NULL)
	{
		return "Unable to open the image file\n";
    //return 1;
	}

	char buf[8];
	if (fread(buf, 1, sizeof (buf), fp) != sizeof(buf))
	{
		return "Unable to read file contents.\n";
    //fclose(fp);
    //return 1;
	}

	if (buf[0] == '\x89' &&
		buf[1] == '\x50' &&
		buf[2] == '\x4E' &&
		buf[3] == '\x47' &&
		buf[4] == '\x0D' &&
		buf[5] == '\x0A' &&
		buf[6] == '\x1A' &&
		buf[7] == '\x0A')
	{
    //PNG
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\xFF' && 
		buf[1] == '\xD8' && 
		buf[2] == '\xFF' &&
		buf[3] == '\xE0')
	{
    //JPG
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\xFF' && 
		buf[1] == '\xD8' && 
		buf[2] == '\xFF' &&
		buf[3] == '\xE1')
	{
    //JPG
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\xFF' && 
		buf[1] == '\xD8' && 
		buf[2] == '\xFF' &&
		buf[3] == '\xE8')
	{
    //JPG
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\x25' && 
		buf[1] == '\x50' && 
		buf[2] == '\x44' &&
		buf[3] == '\x46')
	{
    //PDF
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\xC5' && 
		buf[1] == '\xD0' && 
		buf[2] == '\xD3' &&
		buf[3] == '\xC6')
	{
    //EPS
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\x25' && 
		buf[1] == '\x21' && 
		buf[2] == '\x50' &&
		buf[3] == '\x53' &&
		buf[4] == '\x2D' &&
		buf[5] == '\x41' &&
		buf[6] == '\x64' &&
		buf[7] == '\x6F')
	{
    //EPS
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\x49' && 
		buf[1] == '\x20' && 
		buf[2] == '\x49')
	{
    //TIFF
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\x49' && 
		buf[1] == '\x49' && 
		buf[2] == '\x2A' &&
		buf[3] == '\x00')
	{
    //TIFF
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\x4D' && 
		buf[1] == '\x4D' && 
		buf[2] == '\x00' &&
		buf[3] == '\x2A')
	{
    //TIFF
    image_in.write(directory);
    return directory;
	}
	else if (buf[0] == '\x4D' && 
		buf[1] == '\x4D' && 
		buf[2] == '\x00' &&
		buf[3] == '\x2B')
	{
    //TIFF
    image_in.write(directory);
    return directory;
	}
	else
	{
    return "No image signature found.\n";
	}
	
	fclose (fp);
}

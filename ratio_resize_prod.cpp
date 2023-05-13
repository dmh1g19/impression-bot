#include "ProductList.h"

//product and artwork image comes in as the following: Width x Height
cv::Size ratio_resize_prod(double width, double height, cv::Mat image, std::string image_name, std::string directory)
{
	//convert the int intput to string for the image.scale() function
  std::stringstream val;
	if (height > width)
		val << height;
	else
		val << width;

  std::string value = val.str();

	//perform image operations
  Magick::Image image_in;
	image_in.read(image_name);
	image_in.scale(value+"x"+value);
	//image_in.scale(width_string);
	image_in.write(directory+"output.png");

  cv::Mat final_image = cv::imread(directory+"output.png", -1);
  cv::Size final_size(final_image.size().width, final_image.size().height);
	
	return final_size;
}

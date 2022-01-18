#include "ProductList.h"

//product and artwork image comes in as the following: Width x Height
cv::Size ratio_resize_logo(double width, double height, double prod_w, double prod_h, cv::Mat image, std::string image_name, std::string directory)
{
	double logo_h = image.size().height;
	double logo_w = image.size().width;

  std::stringstream w;
	w << width;
  std::stringstream h;
	h << height;
  std::string str_w = w.str();
	std::string str_h = h.str();

	//perform image operations
  Magick::Image image_in;
	image_in.read(image_name);

	if (prod_w > prod_h && logo_w > logo_h && logo_h > height)
		image_in.scale(str_w+"x"+str_h);
	else if (prod_w > prod_h && logo_w > logo_h)
    image_in.scale(str_w+"x"+str_w);
	else if (prod_w > prod_h && logo_h > logo_w) //xertical 1110 scale(wxw)
		image_in.scale(str_h+"x"+str_h);
	else if (prod_h > prod_w && logo_h > logo_w) //2432	
		image_in.scale(str_w+"x"+str_h);
	else if (prod_h > prod_w && logo_w > logo_h) //2432
		image_in.scale(str_w+"x"+str_w);
	else if (logo_w == logo_h && width < height) //if logo is square
		image_in.scale(str_w+"x"+str_w);
	else if (logo_w == logo_h) //if logo is square
		image_in.scale(str_h+"x"+str_h);
	else if (prod_w == prod_h && height < width && logo_w > logo_h)
		image_in.scale(str_w+"x"+str_w);
	else if (prod_w == prod_h && height < width && logo_h > logo_w)
		image_in.scale(str_h+"x"+str_h);
	else if (width < height)
		image_in.scale(str_w+"x"+str_w);
	else
		image_in.scale(str_h+"x"+str_h);

	//create temp files
	image_in.write(directory+"output2.png");
  cv::Mat final_image = cv::imread(directory+"output2.png", -1);

  cv::Size final_size(final_image.size().width, final_image.size().height);
	
	return final_size;
}

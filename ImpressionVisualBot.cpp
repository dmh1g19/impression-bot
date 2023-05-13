//The product image(background) must contain no alpha channel(3 channel)
//and the logo(foreground) must contain an alpha channel(4 channel)

#include "ProductList.h"

int main()
{
	printf("\033c");
	const char *DIR_NAME = "./products/";
	std::string DIR_NAME_LOGO = "./images/";
	std::string DIR_OUTPUT = "./output/";
	std::string userDataInput; //product number
	std::string colourChoice;  //product colour choice
	std::string ImageInput1;   //product image
	std::string ImageInput2;   //logo image

	std::cout << UNDL(BOLD(FRED("\n--- Impression Visual Bot ---")));
	std::cout << FMAG("\nPlease type on the corresponding numbers to provided questions.\n");
	std::cout << BOLD(FMAG("\nType in the product number: "));
	std::cin >> userDataInput;

	std::cout << BOLD(FMAG("Pick colour of product: "));
	std::cin >> colourChoice;

	std::cout << BOLD(FMAG("Type in the second image: "));
	std::cin >> ImageInput2;

	std::cout << FMAG("\nCalculating, please wait...\n");

	//Regular Expression to navigate through the directory - linux/mac
	ImageInput1 = regexing((char *)DIR_NAME, userDataInput, colourChoice);

	//Turns the JPG image into a png without white pixels 
	cv::Mat image2 = turnToAlpha(DIR_NAME_LOGO+ImageInput2);

  //Convert const char to string
	std::string dir_converted(DIR_NAME);
  
  //Read the product image file
 	cv::Mat image1 = cv::imread(dir_converted + "/" + ImageInput1);

  //Read the product image file
 	cv::Mat image1_size = cv::imread(dir_converted + "/" + ImageInput1);

	std::string image1_full_path = DIR_NAME+ImageInput1; //full path for product image
	std::string image2_full_path = DIR_OUTPUT+"converted_image.jpg"; //full path for logo image

	double height_of_prod = print_area_pixels_height_prod(userDataInput);
	double width_of_prod = print_area_pixels_width_prod(userDataInput);
	
	resize(image1, image1, ratio_resize_prod(width_of_prod, height_of_prod, image1, image1_full_path, DIR_OUTPUT));

	if( image1.empty())
	{
    std::cout <<  FRED("\nCould not open or find the PRODUCT image from regex.\n");
    return -1;
	}
	else if( image2.empty())
	{
    std::cout <<  FRED("\nCould not open or find the ARTWORK image.\n");
    return -1;
	}

	cv::Mat result;

	imwrite(DIR_OUTPUT+userDataInput+".jpg", productList((userDataInput),image2_full_path , image2, image1, colourChoice, result, image1_size, DIR_OUTPUT));
	return_product_data(userDataInput); //print out the product data from the CSV file to the terminal
	std::cout << "\n-----------------------------------------------\n";
	std::cout << FCYN("Image saved in: ") + DIR_OUTPUT << '\n' << std::endl;

	//clean up - remove temp logo and image files
	remove((DIR_OUTPUT+"output2.png").c_str());
	remove((DIR_OUTPUT+"output.png").c_str());
  remove((DIR_OUTPUT+"converted_image.jpg").c_str());

	return 0;
}

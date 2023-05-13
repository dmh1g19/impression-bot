#include "ProductList.h"

//Default print positions
int CENTRAL = 95;
int TOP_CENTRAL = 265;
int BOTTOM_CENTRAL = 115;

//image2(logo) = b, image1(image) = c, choice = position choice
cv::Mat productList(std::string a, std::string logo_dir, cv::Mat b, cv::Mat c, std::string colChoice, cv::Mat final_image, cv::Mat image_size, std::string directory)
{
	//apply new size transformations to logo but keep ratio
  double prod_w = c.size().width;
	double prod_h = c.size().height;

	resize(b, b, ratio_resize_logo(print_area_pixels(a,true), print_area_pixels(a,false), print_area_pixels(a,true), print_area_pixels(a,false), b, logo_dir, directory));

	std::string manual_input;
	std::cout << BOLD(FMAG("\nManually place artwork onto product?"));
	std::cout << FMAG("\nMove the logo image with 'w, a, s, d' (press ENTER when done).\n");
	std::cout <<  FMAG("(yes or no): ");
	std::cin >> manual_input;

	std::string a_full = a + cv::string("-") + colChoice;
	colChoice = cv::string("-") + colChoice;
  
	if (manual_input == "yes" || manual_input == "y")
	{
    if(find_values_x(a) && find_values_y(a))
		{
      std::cout << FMAG("Data already present has been used, please remove data and re run for new artwork location.\n");
			int x_cor = find_values_x(a);		
			int y_cor = find_values_y(a);
			overlayImage(c, b, final_image, cv::Point(x_cor, y_cor));
		}
		else
		{
			place_interactive(a, c, b); //product std::string, product, logo
			int x_cor = find_values_x(a);		
			int y_cor = find_values_y(a);
      std::cout << "x: " << x_cor << std::endl;
      std::cout << "y: " << y_cor << std::endl;
			overlayImage(c, b, final_image, cv::Point(x_cor, y_cor));
		}
	}
	else if (manual_input == "no" || manual_input == "n")
	{
		if (a_full == cv::string("3076") + colChoice)
		{
			
			std::cout << BOLD(FMAG("\nImage position?\n"));
			std::cout << FMAG("1. Central\t2. Top central\t3. Bottom Central\n");
			int choice;
			std::cin.clear();
			std::cin >> choice;

			if (choice==1)
				overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)-CENTRAL)); 
			else if(choice==2)
        overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)-TOP_CENTRAL)); 
			else if(choice==3)
				overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)+BOTTOM_CENTRAL)); 
		}
		else 
      //place logo centrally onto product image by default
			overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2))); 
	}
	else
		std::cout << "Please type yes or no.\n";
	
	return final_image;
}

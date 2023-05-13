// to see more info on working with images with alpha cannel: https://docs.opencv.org/3.4.1/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56

#include "ProductList.h"

cv::Mat turnToAlpha(std::string imagePlace)
{
	int choice;
	std::cout << BOLD(FMAG("\nArtwork background colour to be removed?"));
	std::cout << FMAG("\n1.White\t\t2.Black\n");
	std::cin >> choice;

    //std::cout << "TEST: " << image_type(imagePlace) << std::endl;

	cv::Mat input = cv::imread(image_type(imagePlace), -1);
	cv::Mat input_bgra;
	cvtColor(input, input_bgra, CV_BGR2BGRA);

	if (choice == 1)
	{
		// find all white pixel and set alpha value to zero:
		for (int y = 0; y < input_bgra.rows; ++y)
		for (int x = 0; x < input_bgra.cols; ++x)
		{
      cv::Vec4b & pixel = input_bgra.at<cv::Vec4b>(y, x);
			// if pixel is white
			int thres = 150; // where thres is some value smaller but near to 255(white).
      if (pixel[0] >= thres&& pixel[1] >= thres && pixel[2] >= thres)
			{
				// set alpha to zero:
				pixel[3] = 0;
			}
		}
	}
	else if (choice == 2)
	{
        // find all white pixel and set alpha value to zero:
        for (int y = 0; y < input_bgra.rows; ++y)
        for (int x = 0; x < input_bgra.cols; ++x)
        {
          cv::Vec4b & pixel = input_bgra.at<cv::Vec4b>(y, x);
          // if pixel is white
          int thres = 10; // where thres is some value greater but near to 0(black).
          if (pixel[0] <= thres && pixel[1] <= thres && pixel[2] <= thres)
          {
            // set alpha to zero:
            pixel[3] = 0;
          }
        }
	}
	
	return input_bgra; //return input for non alpha logo
}

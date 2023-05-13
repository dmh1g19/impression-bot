#include "ProductList.h"

cv::Mat rawImage;

std::string regexing(char *dir_name, std::string userData, std::string colourChoice)
{
	//string ImageInput1;
	DIR *directory; 
	struct dirent *_dirent;
  std::string temp_file_name;

	//open directory
	directory = opendir(dir_name);
	//read files
 	while((_dirent = readdir(directory)) != NULL)
 	{
    std::string fileName = cv::string(dir_name) + "/" + cv::string(_dirent->d_name);
    cv::Mat rawImage = cv::imread(fileName.c_str());

		//find the correct file
    std::regex r(userData + cv::string("-") + colourChoice); //regex condition number 1 - r
		std::regex t("FRT");	//regex condition number 2 - t
		std::regex u("TOP"); //regex condition number 3 - u
	  bool match = regex_search(fileName, r);
		bool match2 = regex_search(fileName, t);
		bool match3 = regex_search(fileName, u);
		if((match==true && match2==true) || (match==true && match3==true))
		{
			temp_file_name = SplitFilename(fileName);

			std::cout << FCYN("Product image found -> ") << temp_file_name << std::endl;
			return temp_file_name;
			break;
		}
    else {
		  std::cout << FRED("\nPlease Note: Product Image not found!\n");
    }
  }
	closedir(directory);
	
 	if(!directory)
		std::cout << FRED("Cannot open Input Folder\n");
	else if(rawImage.data == NULL)
		std::cout << FRED("\nPlease Note Cannot Open Image: Image file might not exist.\n");
}

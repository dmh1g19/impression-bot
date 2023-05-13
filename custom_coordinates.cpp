#include "ProductList.h"

void custom_coordinates(std::string code, int x, int y)
{
  std::vector<std::string> tok;

  std::fstream myfile;
  myfile.open("./placement_xy.csv", std::ios::in | std::ios::out | std::ios::app);

  if (!myfile)
      std::cout << "Failed to open file" << std::endl;

  std::stringstream prod;
	std::stringstream horizontal;
	std::stringstream vertical;
	horizontal << x;
	vertical << y;
	prod << code;
	std::string str_x = horizontal.str();
	std::string str_y = vertical.str();
	std::string str_code = prod.str();

  // TEMP SOLUTION // - Plug values straight
  myfile << str_code + ",";
  myfile << str_x + ",";
  myfile << str_y + "\n";
}

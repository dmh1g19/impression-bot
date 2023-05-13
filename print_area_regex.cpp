#include "ProductList.h"

double MULTIPLIER = 5; //multiplier to scale the the product and artwork larger so resolution isn't too low
float PIXEL_DIM = 3.7;
std::ifstream myfile ("./products_list_edited.csv");

double print_area_pixels(std::string code, bool width)
{
  std::vector<std::string> tok;

  std::string line = "";
  while(std::getline(myfile, line))
  {
    std::stringstream strstr(line);
    std::string word = "";
    while(std::getline(strstr, word, ',')) tok.push_back(word);
  }

  //regex
  std::string print_area_string;
  int index;
  if (width) {
      index = 2;
  } else {
      index = 4;
  }
  for (unsigned i=0;i<tok.size();i++)
  {
    if (tok[i] == code)
    {
      print_area_string = tok[i+index];
      break;
    }
  }

  //separate print area width and height values
  std::string temp = print_area_string;
  std::string print_area_del_width;
  std::string print_area_del_height;

  int total = 0;
  for (int i=0;i<print_area_string.length();i++)
  {
    total++;
    if(print_area_string[i] == 'x') //width
    {
      print_area_del_width = temp.erase(i, total+1);
    }

    temp = print_area_string;
    if(print_area_string[i] == 'x') //height
    {
      print_area_del_height = temp.erase(0, i+2);
    }
  }

  std::stringstream width_ss(print_area_del_width);
  std::stringstream height_ss(print_area_del_height);
  double prod_width;
  double prod_height;
  width_ss >> prod_width; //value converted to int
  height_ss >> prod_height; //value converted to int

  if (width) {
      double width_pixels_mm = prod_width * 10; //convert to mm from cm
      double width_pixels_prod = width_pixels_mm*MULTIPLIER;
      return width_pixels_prod;
  } else {
      double height_pixels_mm = prod_height * 10; //convert to mm from cm
      double height_pixels_prod = height_pixels_mm*MULTIPLIER;
      return height_pixels_prod;
  }
}
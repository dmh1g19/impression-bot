#include "ProductList.h"

double MULTIPLIER3 = 5; //default 5
float PIXEL_DIM3 = 3.7;
std::ifstream myfile4 ("./products_list_edited.csv");

double print_area_pixels_width_prod(std::string code)
{
  std::vector<std::string> tok;
      
  std::string line = "";
  while(std::getline(myfile4, line))
  {
    std::stringstream strstr(line);
    std::string word = "";
    while(std::getline(strstr, word, ',')) tok.push_back(word);
  }
      
  //regex
  std::string print_area_string;
  for (unsigned i=0;i<tok.size();i++)
  {
    if (tok[i] == code)
    {
      print_area_string = tok[i+4];
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
      
  std::stringstream width(print_area_del_width);
  std::stringstream height(print_area_del_height);
  double prod_width;
  double prod_height;
  width >> prod_width; //value converted to int
  height >> prod_height; //value converted to int
      
  double width_pixels_mm = prod_width * 10; //convert to mm from cm
  double width_pixels_prod = width_pixels_mm*MULTIPLIER3;
  return width_pixels_prod;
}

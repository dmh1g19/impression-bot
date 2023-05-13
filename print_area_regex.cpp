#include "ProductList.h"

double MULTIPLIER = 5; //multiplier to scale the the product and artwork larger so resolution isn't too low
float PIXEL_DIM = 3.7;
std::ifstream myfile ("./products_list_edited.csv");

double print_area_pixels_width(std::string code)
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
  for (unsigned i=0;i<tok.size();i++)
  {
    if (tok[i] == code)
    {
      print_area_string = tok[i+2];
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
  double  prod_width;
  double  prod_height;
  width >> prod_width; //value converted to int
  height >> prod_height; //value converted to int
      
  double width_pixels = prod_width*MULTIPLIER; //need to remove 20mm from final artwork
      
  return width_pixels;
}

double print_area_pixels_height(std::string code)
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
  for (unsigned i=0;i<tok.size();i++)
  {
    if (tok[i] == code)
    {
      print_area_string = tok[i+2];
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
  double  prod_width;
  double  prod_height;
  width >> prod_width; //value converted to int
  height >> prod_height; //value converted to int
      
  //double heigth_pixels = ((prod_height * PIXEL_DIM)-(PIXEL_DIM*20))*MULTIPLIER;
  double heigth_pixels = prod_height*MULTIPLIER;
      
  return heigth_pixels;
}

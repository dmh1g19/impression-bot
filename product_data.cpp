#include "ProductList.h"

std::ifstream myfile3 ("./products_list_edited.csv");

void return_product_data(std::string code)
{
  std::vector<std::string> specs;
  
  std::string line = "";
  while(std::getline(myfile3, line))
  {
    std::stringstream strstr(line);
    std::string word = "";
    while(std::getline(strstr, word, ',')) specs.push_back(word);
  }
  
  std::cout << '\n';
  //regex
  std::string print_area_string;
  for (unsigned i=0;i<specs.size();i++)
  {
    if (specs[i] == code)
    {
      std::cout << FCYN("Product code: ") << specs[i] << std::endl;
      std::cout << FCYN("Item: ") << specs[i+1] << std::endl;
      std::cout << FCYN("Print area: ") << specs[i+2] << " mm" << std::endl;
      std::cout << FCYN("Product dimensions: ") << specs[i+4] << " cm" << std::endl;
      std::cout << FCYN("Materials: ") << specs[i+5] << std::endl;
      break;
    }
  }
}

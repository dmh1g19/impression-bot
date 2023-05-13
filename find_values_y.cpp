#include "ProductList.h"

int find_values_y(std::string code)
{
  std::ifstream myfile ("./placement_xy.csv");

  std::vector<std::string> tok;
	
  std::string line = "";
	while(std::getline(myfile, line))
	{
    std::stringstream strstr(line);
    std::string word = "";
    while(std::getline(strstr, word, ',')) 
    tok.push_back(word);
	}

  std::string x, y = "";
	for (int i=0;i<tok.size();i++)
  {
		if (tok[i] == code)
		{
			x = tok[i+1];
			y = tok[i+2];
		}
  }

	int int_x, int_y = 0;
  std::istringstream ss_x(x);
	std::istringstream ss_y(y);
	ss_x >> int_x;
	ss_y >> int_y;

	return int_y;
}

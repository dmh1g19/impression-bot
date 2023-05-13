#include "ProductList.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

std::unordered_map<std::string, std::pair<int, int>> placement_map;

void load_placement_csv() {
  std::ifstream myfile("./placement_xy.csv");
  std::string line;
  while (std::getline(myfile, line)) {
    std::stringstream ss(line);
    std::string code, x, y;
    std::getline(ss, code, ',');
    std::getline(ss, x, ',');
    std::getline(ss, y, ',');
    int int_x = std::stoi(x);
    int int_y = std::stoi(y);
    placement_map[code] = std::make_pair(int_x, int_y);
  }
}

int find_values_x(std::string code) {
  if (placement_map.empty()) {
    load_placement_csv();
  }
  return placement_map[code].first;
}

int find_values_y(std::string code) {
  if (placement_map.empty()) {
    load_placement_csv();
  }
  return placement_map[code].second;
}
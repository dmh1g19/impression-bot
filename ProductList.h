#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <regex>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctype.h>
#include <sstream>
#include "text_colour.h"
#include <Magick++.h>
#include <sstream>
#include <curses.h>

//Finding correct product specs
cv::Mat productList(std::string, std::string, cv::Mat, cv::Mat, std::string, cv::Mat, cv::Mat, std::string);

//Add alpha channel
cv::Mat turnToAlpha(std::string);
cv::Mat down_size(cv::Mat, cv::Mat);

cv::Size ratio_resize_prod(double, double, cv::Mat, std::string, std::string);
cv::Size ratio_resize_logo(double, double, double, double, cv::Mat, std::string, std::string);

//Regex for walking directory
std::string regexing(char *dir_name, std::string, std::string);
std::string image_type(std::string);

 //retrieve file name for regex
std::string SplitFilename (const std::string& str);

void return_product_data(std::string);
void overlayImage(const cv::Mat &, const cv::Mat &, cv::Mat &, cv::Point2i);
void place_interactive(std::string, cv::Mat, cv::Mat);
void custom_coordinates(std::string, int, int);

double print_area_pixels(std::string code, bool width);

int find_values_x(std::string);
int find_values_y(std::string);
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

cv::Mat productList(std::string, std::string, cv::Mat, cv::Mat, std::string, cv::Mat, cv::Mat, std::string); //finding correct product specs
cv::Mat turnToAlpha(std::string); //add alpha channel
cv::Mat down_size(cv::Mat, cv::Mat);

cv::Size ratio_resize_prod(double, double, cv::Mat, std::string, std::string);
cv::Size ratio_resize_logo(double, double, double, double, cv::Mat, std::string, std::string);

std::string regexing(char *dir_name, std::string, std::string); //regex for walking directory
std::string image_type(std::string);
std::string SplitFilename (const std::string& str); //retrieve file name for regex

void return_product_data(std::string);
void overlayImage(const cv::Mat &, const cv::Mat &, cv::Mat &, cv::Point2i);
void place_interactive(std::string, cv::Mat, cv::Mat);
void custom_coordinates(std::string, int, int);

double print_area_pixels_width(std::string code);
double print_area_pixels_height(std::string code);
double print_area_pixels_height_prod(std::string code);
double print_area_pixels_width_prod(std::string code);

int find_values_x(std::string);
int find_values_y(std::string);

#include "ProductList.h"

cv::Mat down_size(cv::Mat image_size, cv::Mat image)
{
  cv::Size resized_image(image_size.size().width, image_size.size().height);

	resize(image, image, resized_image);

	return image;
}

#include <opencv4/opencv2/core/mat.hpp>
#include <vector>

#ifndef MATHEMATICS_H
#define MATHEMATICS_H

cv::Mat convolution(const cv::Mat& image, const cv::Mat& kernel);

// namespace Math {
// class Operations
// {
// public:
//     cv::Mat convolution(cv::Mat& image, cv::Mat& kernel);
// };
// }

#endif

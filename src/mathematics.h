#include <opencv4/opencv2/core/mat.hpp>
#include <vector>

#ifndef MATHEMATICS_H
#define MATHEMATICS_H

namespace Math {
class Operations
{
public:
    cv::Mat convolution(cv::Mat& image, cv::Mat& kernel);
};
}

#endif

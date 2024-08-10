#include <opencv4/opencv2/core/mat.hpp>
#include <vector>

#ifndef MATHEMATICS_H
#define MATHEMATICS_H

namespace Math {
class Operations
{
public:
    template <typename T, size_t N, size_t M>
    cv::Mat convolution(cv::Mat image, const T (&a)[N][M]);
};
}

#endif

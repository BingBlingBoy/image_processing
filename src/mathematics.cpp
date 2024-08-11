#include "menu.h"
#include "mathematics.h"
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/hal/interface.h>
#include <opencv4/opencv2/core/mat.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <vector>

using namespace Math;

cv::Mat Operations::convolution(cv::Mat& image, cv::Mat& kernel)
{
    std::vector<cv::Mat> split_image_channel {};
    std::vector<cv::Mat> split_kernel {};

    if (image.channels() == 3)
    {
        cv::split(image, split_image_channel);
    }
    else if (image.channels() == 2)
    {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        cv::split(image, split_image_channel);
    }
    // Add error checking

    cv::split(kernel, split_kernel);

    int y_strides = split_image_channel[0].cols - split_kernel[0].cols + 1;
    int x_strides = split_image_channel[1].rows - split_image_channel[1].rows + 1;

    cv::Mat output = cv::Mat::zeros(y_strides, x_strides, CV_32F);
    cv::Mat output_temp = output.reshape(image.channels(), y_strides * x_strides);

    int count = 0;

    for (int i; i < y_strides; ++i)
    {
        for (int j; j < x_strides; ++i)
        {
            int loop = 0; 
            for (const auto& x: split_image_channel)
            {
                cv::Mat subMatrix = x(cv::Rect(i, j, split_kernel[0].cols, split_kernel[1].rows));
                output_temp.at<double>(count, loop) = cv::sum(x.mul(subMatrix))[0];
                loop += 1;
            }
        }
    }

    output = output_temp.reshape(1, x_strides);

    return output;
}

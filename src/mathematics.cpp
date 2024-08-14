#include "mathematics.h"
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/hal/interface.h>
#include <opencv4/opencv2/core/mat.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <vector>

// using namespace Math;

cv::Mat /* Operations:: */convolution(const cv::Mat& image, const cv::Mat& kernel)
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


    int x_strides = split_image_channel[0].cols - kernel.cols + 1;
    int y_strides = split_image_channel[0].rows - kernel.rows + 1;

    cv::Mat output = cv::Mat::zeros(x_strides, y_strides, CV_8SC3);
    
    cv::Mat output_temp = output.reshape(1, (y_strides * x_strides * output.channels()) / 3);

    int count = 0;

    for (int i; i < y_strides; ++i)
    {
        for (int j; j < x_strides; ++j)
        {
            int loop = 0; 
            for (const auto& x: split_image_channel)
            {
                cv::Mat subMatrix = x(cv::Rect(j, i, kernel.cols, kernel.rows));

                cv::Mat kernel_converted;
                kernel.convertTo(kernel_converted, subMatrix.type());
                output_temp.at<int>(count, loop) = cv::sum(kernel_converted.mul(subMatrix))[0];
                loop += 1;
            }
        }
    }

    output = output_temp.reshape(3, y_strides);
    std::cout << output.cols << '\n';
    std::cout << output.rows << '\n';
    std::cout << output.channels() << '\n';

    return output;
}

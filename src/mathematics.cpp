#include "mathematics.h"
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/hal/interface.h>
#include <opencv4/opencv2/core/mat.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <cmath>
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

template <typename T, typename U>
cv::Mat Gernerate_Gaussian_Kernel (U sigma, const std::vector<T>& filter_size)
{
    T m = filter_size[0];
    T n = filter_size[1];

    T m_half = m / 2;
    T n_half = m / 2;

    cv::Mat gaussian_filter = cv::Mat::zeros(m, n, CV_32F);
    double converted_sigma = static_cast<double>(sigma);

    for (int y = -m_half; y < m_half; ++y)
    {
        for (int x = -n_half; x < n_half; ++x)
        {
            double normal = 1 / (2.0 * M_PI * std::pow(converted_sigma, 2));
            double exp = std::exp(-(std::pow(x, 2) + std::pow(y, 2)) / (2 * std::pow(converted_sigma, 2)));
            gaussian_filter[y+m_half, x+n_half] = normal * exp;
        }
    }

    return gaussian_filter;
}

#include <iostream>
#include <opencv4/opencv2/core/hal/interface.h>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include "menu.h"
 
using namespace cv;
    
int main(int argc, char* argv[])
{
    std::cout << "Welcome to the greatest image processing application the world has ever seen!" << '\n';
    
    User::Input user {};
    user.getUserFileInput();
    // std::cout << user.getInput() << '\n';


    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread(user.m_input, IMREAD_COLOR);
    user.setImage(image);

    std::cout << user.shape() << '\n';


    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }

    // std::cout << image << '\n';

    // To get shape of a matrix, add values to vector and return a vector

    // std::cout << "Image rows: " << image.rows << '\n';
    // std::cout << "Image cols: " << image.cols << '\n';
    //
    // for (int i {0}; i < image.rows; ++i) {
    //     for (int j {0}; j < image.cols; ++j) {
    //         if (i < 174 && j < 50)
    //         {
    //             image.at<double>(i, j) = 0;
    //         }
    //         std::cout << std::fixed << std::setprecision(2) << image.at<double>(i, j) << " ";
    //     } 
    //     std::cout << '\n';
    // }

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}

#include <iostream>
#include <opencv4/opencv2/core/mat.hpp>
#include <string>
#include <limits>
#include <string_view>
#include "mathematics.h"


#ifndef MENU_H
#define MENU_H

namespace User
{
    class Input: public Math::Operations
    {
    private:
        cv::Mat m_image {};

    public:
        Input() = default;
        
        // const std::string_view getInput() const {return m_input;}
        std::string m_input {};
        void getUserFileInput();
        void setImage(cv::Mat image)
        {
            m_image = image;
        }
        const cv::Mat getImage() const {return m_image;}
        
    public:
        int image_shape()
        {
            if (m_input.empty()) {
                return -69;
            }
            return getImage().channels();
        }
    };
}

#endif

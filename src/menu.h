#include <iostream>
#include <string>
#include <limits>
#include <string_view>

#ifndef MENU_H
#define MENU_H

namespace User {
    class Input
    {
    private:
        std::string m_input {};

    private:
        void ignoreLine();
        bool clearFailedExtraction();
        bool checkValidFilePath(std::string& filePath);
    public:
        Input() = default;
        
        std::string_view getInput() const {return m_input;}
        void getUserFileInput();
    };
}

#endif

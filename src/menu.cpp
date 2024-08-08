#include "menu.h"
#include "error_checking.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/stat.h>

using namespace User;

void Input::getUserFileInput()
{
    while (true)
    {
        std::string file {};
        std::cout << "Enter the file path you would like to edit: ";
        // getline(std::cin >> std::ws, file);
        std::cin >> file;

        if (ErrorChecking::clearFailedExtraction())
        {
            std::cout << "Input is invalid. Please try again \n";
            continue;
        }
        
        if (!ErrorChecking::checkValidFilePath(file))
        {
            std::cout << "'" << file << "'" << " does not exists\n";
            continue;
        }

        ErrorChecking::ignoreLine();
        m_input = file;
        break;
    }
}



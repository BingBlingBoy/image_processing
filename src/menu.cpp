#include "menu.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <sys/stat.h>
#include <filesystem>


using namespace User;
namespace fs = std::filesystem;

void Input::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Input::checkValidFilePath(std::string& filePath)
{
    const fs::path imagePath {filePath};
    fs::file_status s = fs::file_status{};
    if (fs::exists(imagePath))
    {
        return true;
    }
    else
    {
        std::cout << imagePath << " does not exist\n";
        return false;
    }
}

bool Input::clearFailedExtraction()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            exit(0);
        }

        std::cin.clear();
        ignoreLine();

        return true;
    }

    return false;
}

void Input::getUserFileInput()
{
    while (true)
    {
        std::string file {};
        std::cout << "Enter the file path you would like to edit: ";
        // getline(std::cin >> std::ws, file);
        std::cin >> file;

        if (clearFailedExtraction())
        {
            std::cout << "Input is invalid. Please try again \n";
            continue;
        }
        
        if (!checkValidFilePath(file))
        {
            std::cout << file << " does not exists\n";
            continue;
        }

        ignoreLine();
        m_input = file;
        break;
    }
}



#include "error_checking.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <sys/stat.h>
#include <filesystem>

namespace fs = std::filesystem;

void ErrorChecking::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool ErrorChecking::checkValidFilePath(std::string& filePath)
{
    const fs::path imagePath {filePath};
    fs::file_status s = fs::file_status{};
    if (fs::exists(imagePath))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ErrorChecking::clearFailedExtraction()
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

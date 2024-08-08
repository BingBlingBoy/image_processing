#include <string>

#ifndef ERRORCHECKING_H
#define ERRORCHECKING_H

namespace ErrorChecking {
    void ignoreLine();
    bool clearFailedExtraction();
    bool checkValidFilePath(std::string& filePath);
};

#endif

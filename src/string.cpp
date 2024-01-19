
#include "string.h"
#include <vector>

bool isValidInputFormat(int size, const std::vector<int>& args) {
    // Check if the size is greater than 0
    if (size <= 0) {
        return false;
    }

    // Check if additional arguments are valid (1 or 2)
    for (int arg : args) {
        if (arg != 1 && arg != 2) {
            return false;
        }
    }

    // If all checks pass, return true
    return true;
}


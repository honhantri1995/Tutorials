#include "util.h"
#include <algorithm>

std::string to_upper(const std::string &input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}
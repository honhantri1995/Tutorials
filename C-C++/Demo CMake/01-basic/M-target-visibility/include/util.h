//////////////////// For PUBLIC and PRIVATE //////////////////////
#pragma once
#include <string>

std::string to_upper(const std::string &input);


//////////////////// For INTERFACE //////////////////////
// #pragma once

// #include <string>
// #include <algorithm>

// inline std::string to_upper(const std::string &input) {
//     std::string result = input;
//     std::transform(result.begin(), result.end(), result.begin(), ::toupper);
//     return result;
// }
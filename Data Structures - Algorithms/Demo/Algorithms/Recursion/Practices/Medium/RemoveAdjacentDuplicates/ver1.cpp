// Input: s = "geeksforgeek". Output: "gksforgk"
// Input: s = "abccbccba". Output: ""
// Input: s = "abcd". Output: "abcd"

#include <iostream>
#include <cstdarg>
using namespace std;

void log(string level, int line, const char* format, ...) { // TODO: This function is useless, just printf is fine
    std::cout << "[" << level << "] [Line " << line << "] ";

    va_list args;
    va_start(args, format);

    vprintf(format, args); // Print the formatted string
    std::cout << std::endl; // Print a newline

    va_end(args);
}

#define LOG(level, ...) log(level, __LINE__, __VA_ARGS__)

string outStr = "";

void remove(string inStr) {                                 // time O(n^2)
    int inLen = inStr.length();
    int outLen = outStr.length();
    LOG("D", "outLen %d", outLen);
    string tmpStr = "";                                     // TODO: Using a tmp increases memory usage: O(n^2) --> fixed at ver2
    for (int idx = 0; idx < inLen; idx++) {                 // time O(n)
        bool dup = false;
        while ((inStr[idx] == inStr[idx+1]) && (idx < inLen - 1)) {        // time O(n)
            idx++;
            dup = true;
            LOG("I", "Found %c", inStr[idx]);
            LOG("D", "Current outStr %s", outStr.c_str());
            LOG("D", "Current tmpStr %s", tmpStr.c_str());
        }
        if (!dup) {
            tmpStr += inStr[idx];
            LOG("D", "Not found %c", inStr[idx]);
        }
    }

    if (tmpStr.length() == outLen) {
        return;
    } else {
        outStr = tmpStr;
    }
    remove(outStr);
}

int main() {
    string inStr = "";
    inStr = "geeksforgeek";
    // inStr = "abccbccba";
    // inStr = "abcd";
    remove(inStr);
    cout << outStr << endl;
    return 0;
}
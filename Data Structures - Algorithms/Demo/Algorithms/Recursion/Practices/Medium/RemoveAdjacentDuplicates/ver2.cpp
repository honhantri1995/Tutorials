// Input: s = "geeksforgeek". Output: "gksforgk"
// Input: s = "abccbccba". Output: ""
// Input: s = "abcd". Output: "abcd"

#include <iostream>
using namespace std;

void remove(string& ioStr) {                                // time O(n^2)
    int ioLen = ioStr.length();
    bool dupAtLeastOnce = false;
    printf("ioLen %d\n", ioLen);
    for (int idx = 0; idx < ioLen; idx++) {                 // time O(n)
        int dupCount = 0;
        while ((ioStr[idx] == ioStr[idx+1]) && (idx < ioLen - 1)) {        // time O(n)
            printf("Found %c\n", ioStr[idx]);
            idx++;
            dupCount++;
            dupAtLeastOnce = true;
        }
        if (dupCount == 0) {
            printf("Not found %c\n", ioStr[idx]);
        } else {
            ioStr.erase(idx - dupCount, dupCount + 1);      // note: std::string::erase will change the index --> need to update the index every time
            idx -= dupCount;
            printf("Current ioStr %s\n", ioStr.c_str());
        }
    }

    if (!dupAtLeastOnce) {
        return;
    }
    remove(ioStr);
}

int main() {
    string str = "";
    str = "geeksforgeek";
    // str = "abccbccba";
    // str = "abcd";

    remove(str);
    cout << str << endl;
    return 0;
}
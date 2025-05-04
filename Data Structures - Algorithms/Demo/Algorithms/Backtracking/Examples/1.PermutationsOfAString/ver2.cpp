#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string str, int index, vector<string>& output, string depth) {
    printf("%sCall permute(%s, %d)\n", depth.c_str(), str.c_str(), index);
    if (index == str.length()) {
        output.emplace_back(str);
        printf("%sBase case. Add %s\n", depth.c_str(), str.c_str());
        return;
    }

    for (int i = index; i < str.length(); i++) {
        if (index != i) {
            swap(str[index], str[i]);
            printf("%sSwap %c and %c at index %d and i %d\n", depth.c_str(), str[index], str[i], index, i);
        } else {
            printf("%sDo not swap %c and %c at index %d and i %d\n", depth.c_str(), str[index], str[i], index, i);
        }
        permute(str, index + 1, output, depth + "  ");
        printf("%sReturn call to permute(%s, %d) at i %d\n", depth.c_str(), str.c_str(), index, i);
    }
}

int main() {
    string str = "ABC";
    // string str = "ABSG";
    vector<string> output = {};
    permute(str, 0, output, "");

    for (const auto& str : output) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
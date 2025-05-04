#include <iostream>
using namespace std;

void search(string text, string pattern) {
    int textSize = text.size();
    int patternSize = pattern.size();

    for (int i = 0; i < textSize - patternSize; i++) {
        for (int j = 0; j < patternSize; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
            if (j == patternSize - 1) {
                cout << "Found pattern at index: " << i << endl;
            }
        }
    }
}

int main() {
    string text = "AABAACAADAABAABAA";
    string pattern = "AABA";

    search(text, pattern);

    return 0;
}
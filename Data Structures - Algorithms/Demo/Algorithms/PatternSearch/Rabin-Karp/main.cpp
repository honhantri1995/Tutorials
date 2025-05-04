#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

#define MODULUS	13

pair<int, int> calHashvalue(string substr, int substrSize, int textSize) {
    int sum = 0;
    for (int i = 0; i < substr.size(); i++) {
        sum += substr[i] * pow(textSize, substrSize - (i + 1));
        cout << substr[i] << " * " << "pow(" << textSize << ", " << substrSize - (i + 1) << ")" << endl;
    }
    int hashValue = sum % MODULUS;
    cout << "Sum: " << sum << ". Hash value: " << hashValue << endl;

    pair<int, int> p(sum, hashValue);
    return p;
}

pair<int, int> slideWindow(int previousSum, char previousChar, char nextChar, int substrSize, int textSize) {
    int sum = ((previousSum - (previousChar * pow(textSize, substrSize - 1))) * textSize) + nextChar;
    int hashValue = sum % MODULUS;
    cout << "PreviousChar: " << previousChar << ". NextChar: " << nextChar << ". Sum: " << sum << ". Hash value: " << hashValue << endl;

    pair<int, int> p(sum, hashValue);
    return p;
}

void search(string text, string pattern) {
    int textSize = text.size();
    int patternSize = pattern.size();

    // Hash value of pattern
    int patternHashValue = calHashvalue(pattern, patternSize, textSize).second;

    // Hash value of first window
    string firstWindow = "";
    for (int i = 0; i < pattern.size(); i++) {
        firstWindow += text[i];
    }
    pair<int, int> firstwindow = calHashvalue(firstWindow, patternSize, textSize);
    int windowSum = firstwindow.first;
    int windowHashValue = firstwindow.second;

    // Check if the pattern and the first window are matched
    if (windowHashValue == patternHashValue) {
        bool found = true;
        cout << "Found potential match" << endl;
        for (int j = 0; j < pattern.size(); j++) {
            if (text[j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "Found match at index: 0" << endl;
        }
    }

    // Check if the pattern and the other windows are matched
    for (int i = 1; i < text.size() - pattern.size() + 1; i++) {
        pair<int, int> p = slideWindow(windowSum, text[i-1], text[i+pattern.size()-1], patternSize, textSize);
        windowSum = p.first;
        windowHashValue = p.second;

        if (windowHashValue == patternHashValue) {
            bool found = true;
            cout << "Found potential match" << endl;
            for (int j = 0; j < pattern.size(); j++) {
                if (text[j+i] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << "Found match at index: " << i << endl;
            }
        }
    }
}

int main() {
    // string text = "AABAACAADAABAABAA";
    // string pattern = "AABA";
    string text = "AACABACCAB";
    string pattern = "CAB";

    search(text, pattern);
    return 0;
}
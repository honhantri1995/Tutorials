#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> outputs;

void print() {
    for (auto &item : outputs) {
        cout << item << " ";
    }
    cout << endl;
}

void doPermute(int idx, string input, int strLen, int& outputSize) {
    for (int j = idx + 1; j < strLen; j++) {
        swap(input[idx], input[j]);
        outputs.emplace_back(input);
        outputSize = outputs.size();
        swap(input[idx], input[j]);
    }
    print();
}

void permute(int strLen, vector<string>& outputs, int& outputSize) {        // O(n^2)
    for (int i = 0; i < outputSize; i++) {
        if (i == 0) {
            doPermute(i, outputs[i], strLen, outputSize);
        } else {
            doPermute(i, outputs[i-1], strLen, outputSize);
        }
        printf("Len of outputs: %d\n", outputSize);
    }
}

int main() {
    string input = "";
    input = "ABC";
    // input = "ABSG";
    // input = "AAA";
    // input = "ABCDEFG";
    // input = "ABSGABCEDR";       // Remove the "print()" to see the result. Otherwise, extremely long time

    int strLen = input.length();

    outputs.emplace_back(input);
    int outputSize = outputs.size();
    permute(strLen, outputs, outputSize);
    print();

    return 0;
}
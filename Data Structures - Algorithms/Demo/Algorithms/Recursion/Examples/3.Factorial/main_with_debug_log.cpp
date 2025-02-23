#include <iostream>
using namespace std;

int fn(int n, string recDepth) {
    printf("%sCall fn(%d)\n", recDepth.c_str(), n);
    if (n < 0) {
        printf("%sBase case\n", recDepth.c_str());
        return -1;
    } else if (n == 0) {
        printf("%sBase case\n", recDepth.c_str());
        return 1;
    } else {
        int result = n * fn(n - 1, recDepth + "  ");
        printf("%sReturn call to fn(%d)\n", recDepth.c_str(), n);
        printf("%sReturn value: %d x fn(%d - 1) = %d\n", recDepth.c_str(), n, n, result);
        return result;
    }
}

int main() {
    int n = 4;
    int result = fn(n, "");
    cout << "Output: " << result << endl;
    return 0;
}

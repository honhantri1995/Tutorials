#include <iostream>
using namespace std;

void fn(int n, string recDepth) {
    printf("%sCall fn(%d)\n", recDepth.c_str(), n);
    if (n > 2) {
        fn(n - 1, recDepth + "  ");
        printf("%sReturn call to fn(%d)\n", recDepth.c_str(), n);
    }
    printf("%sBase case --> print %d\n", recDepth.c_str(), n);
}

int main() {
    fn(5, "");
    return 0;
}
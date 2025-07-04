#include <iostream>
using namespace std;

void fn(int n, string recDepth) {
    printf("%sCall fn(%d)\n", recDepth.c_str(), n);
    if (n > 2) {
        fn(n - 1, recDepth + "  ");
        printf("%sReturn call to fn(%d)\n", recDepth.c_str(), n);
        fn(n - 2, recDepth + "  ");
        printf("%sReturn call to fn(%d)\n", recDepth.c_str(), n);
        fn(n - 3, recDepth + "  ");
        printf("%sReturn call to fn(%d)\n", recDepth.c_str(), n);
    }
    printf("%sBase case", recDepth.c_str());

    cout << " ==> Print " << n << endl;
}

int main() {
    fn(5, "");
    return 0;
}

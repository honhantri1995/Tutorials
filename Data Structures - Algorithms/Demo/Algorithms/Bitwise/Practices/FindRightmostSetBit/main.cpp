#include <iostream>
#include <bitset>
using namespace std;


#define BIT_COUNT_FOR_A_INT   64

// Repeatly right shift 'num' by one unit and check if the result number is an odd.
// Note: Only odd number has the rightmost set bit as bit 1
int way1(int num) {
    for (int i = 0; i < BIT_COUNT_FOR_A_INT; i++) {
        if (num & 1 == 1) {
            return i + 1;
        }
        num = num >> 1;
    }
    return -1;
}

// Repeatly set each bit of the number and XOR with the number itself
int way2(int num) {
    int tmp = 0;
    for (int i = 0; i < BIT_COUNT_FOR_A_INT; i++) {
        tmp = num | (1 << i);
        cout << std::bitset<BIT_COUNT_FOR_A_INT>(tmp) << endl;
        if ((tmp ^ num) == 0) {     // IMPORTANT: Writing "if (tmp ^ num == 0)" is wrong.
            return i + 1;
        }
    }
    return -1;
}

int main() {
    cout << way2(0b0000100) << endl;

    return 0;
}
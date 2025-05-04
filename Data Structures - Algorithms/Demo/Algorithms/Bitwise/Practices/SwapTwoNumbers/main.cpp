#include <iostream>
using namespace std;

/*
	a = 0b111000
	b = 0b000111
	==>
	a = a XOR b = 0b111111
	b = b XOR a = 0b111000
	a = a XOR b = 0b000111
*/

int main() {
    int a = 1;
    int b = 2;

    a = a ^ b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
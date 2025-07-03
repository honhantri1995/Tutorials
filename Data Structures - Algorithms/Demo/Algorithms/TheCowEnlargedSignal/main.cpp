#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream input("cowsignal.in");
    if (!input) {
        cerr << "Fail to read file" << endl;
        return -1;
    }

    int row, col, mul = 0;
    input >> row >> col >> mul;

    cout << "row: " << row << endl;
    cout << "col: " << col << endl;
    cout << "mul: " << mul << endl;

    return 0;
}
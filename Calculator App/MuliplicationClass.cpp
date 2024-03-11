#include "MuliplicationClass.h"
#include <iostream>

using namespace std;


int main() {
    MuliplicationClass multiplier;
    float num3, num4;

    cout << "Enter two numbers: ";
    cin >> num3 >> num4;

    float product = multiplier.multi(num3, num4);
    cout << "Product = " << product << endl;

    return 0;
};

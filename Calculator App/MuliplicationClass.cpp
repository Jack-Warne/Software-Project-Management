#include "MuliplicationClass.h"
#include <iostream>
using namespace std;


int main() {
    MuliplicationClass multiplier;
    double num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    double product = multiplier.multiply(num1, num2);
    cout << "Product = " << product << endl;

    return 0;
};

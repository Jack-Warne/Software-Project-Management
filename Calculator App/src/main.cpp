#include "../MultiplicationClass.h"
#include <iostream>
using namespace std;

//========================================================================
int main() {

    MultiplicationClass multiplier;
    float num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    float product = multiplier.multiply(num1, num2);
    cout << "Product = " << product << "\a" << endl;

    return 0;
};

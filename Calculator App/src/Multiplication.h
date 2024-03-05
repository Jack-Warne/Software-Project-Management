#include <iostream>
using namespace std;

class Calculator {
    float a, b; // Private member variables for the two numbers

public:
    void inputNumbers() {
        cout << "Enter First Number: ";
        cin >> a;
        cout << "Enter Second Number: ";
        cin >> b;
    }

    float multiply() {
        return a * b;
    }
};

int main() {
    Calculator calc;
    calc.inputNumbers(); // Get user input
    float result = calc.multiply(); // Calculate the product
    std::cout << "Product of the two numbers: " << result << std::endl;
    return 0;
}
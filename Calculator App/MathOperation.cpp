#include <iostream>
#include "MathOperation.h" // Assuming this is the correct header file name

using namespace std;

float MathOperation::add(float a, float b) {
    return a + b;
}

float MathOperation::subtract(float a, float b) {
    return a - b;
}

float MathOperation::multiply(float a, float b) {
    return a * b; a;
}

float MathOperation::divide(float a, float b) {
    if (b == 0) {
        // Division by zero error
        return 0; // Just a placeholder because can't return a string yet :DDD
    }
    return a / b;
}

int main() {
    MathOperation math;

    float num1, num2;
    char operation; // To store the user's choice

    // Prompt user for input
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Display menu
    cout << "Choose an operation:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "Enter the operation number (1-4): ";
    cin >> operation;

    float result;
    switch (operation) {
    case '1':
        result = math.add(num1, num2);
        cout << "Result of addition: " << result << "\a" << endl;
        break;
    case '2':
        result = math.subtract(num1, num2);
        cout << "Result of subtraction: " << result << "\a" << endl;
        break;
    case '3':
        result = math.multiply(num1, num2);
        cout << "Result of multiplication: " <<  result << "\a" << endl;
        break;
    case '4':
        result = math.divide(num1, num2);
        cout << "Result of division: " << result << "\a" << endl;
        break;
    default:
        cout << "Invalid operation. Please choose 1, 2, 3, or 4." << endl;
    }

    return 0;
}

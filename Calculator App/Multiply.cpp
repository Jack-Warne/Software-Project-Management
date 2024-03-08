#include <iostream>

class Multiplication {
public:
    int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    using namespace std;

    Multiplication multiplication; // Create an instance of the Multiplication class
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    int result = multiplication.multiply(num1, num2); // Call the multiply method
    cout << "Result: " << result << endl;

    return 0;
}
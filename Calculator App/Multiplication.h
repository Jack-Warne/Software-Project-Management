
#include <iostream>
using namespace std;


class Multiplication{

	int multipy(int a, int b) {
		return a * b;

	}
};

int main() {
	Multiplication multiplication;
	int num1, num2;
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
}

int result = multiplication.multiply(num1, num2);
cout << "Result: " << result << std::endl;

return 0;
}

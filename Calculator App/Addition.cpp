#include <iostream>
#include <vector>

class Addition {
public:
    long long add(const std::vector<long long>& numbers) {
        long long sum = 0; 
        for (long long num : numbers) {
            sum += num;
        }
        return sum;
    }
};

int main() {
    Addition adder;
    std::vector<long long> numbers;

    std::cout << "Enter numbers to add (enter 0 to finish):" << std::endl;
    long long num;
    do {
        std::cin >> num;
        numbers.push_back(num);
    } while (num != 0);

    numbers.pop_back(); // Remove the last 0

    long long result = adder.add(numbers);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

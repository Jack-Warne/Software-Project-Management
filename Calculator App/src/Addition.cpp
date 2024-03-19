#include <iostream>
#include "Addition.h"


double Addition::calculate(double input1, double input2) {
	double answer;
	answer = input1 + input2;
	return answer;
	
}

double Addition::calculatePercentage(double total, double percentage) {
	return (total * percentage) / 100.0f;


}
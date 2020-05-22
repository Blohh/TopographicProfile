#include "Vector.h"
#include "Matrix.h"
#include "LineralEquation.h"
#include <iostream>
#include <fstream>

int main() {
	try {
		std::vector<double> x = { 0, 1, 2, 5 };
		std::vector<double> y = { 2, 3, 12, 147 };
		std::cout << "f(3) = " << myMaths::LineralEquation::LaGrangeInterpolation(3, x, y) <<  std::endl;
	}
	catch (const char* msg) {
		std::cout << "Exception happened!\n" << msg << std::endl;
	}
	return 0;
}

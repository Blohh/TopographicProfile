#include "Vector.h"
#include "Matrix.h"
#include "LineralEquation.h"
#include <iostream>
#include <fstream>
void laGrange();
int main() {
	try {
		laGrange();
	}
	catch (const char* msg) {
		std::cout << "Exception happened!\n" << msg << std::endl;
	}
	return 0;
}
void laGrange() {
	auto F = myMaths::LineralEquation::LaGrangeInterpolation;
	std::vector<double>X_input;
	std::vector<double>Y_input;

	std::ofstream xOutput(output+"X_out.txt"), yOutput(output+"Y_out.txt");
	myMaths::LineralEquation::loadData(X_input, Y_input, "stale.txt", 5);
	for (double xi = X_input[0]; xi < X_input[X_input.size() - 1]; xi += 0.1) {
		xOutput << xi << std::endl;
		yOutput << F(xi, X_input, Y_input) << std::endl;
	}
}
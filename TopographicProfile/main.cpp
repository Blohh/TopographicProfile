#include "Vector.h"
#include "Matrix.h"
#include "LineralEquation.h"
#include <iostream>
#include <fstream>
const std::string filename="stale.txt";
const int per = 50;
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
	std::vector<double>X_test;
	std::vector<double>Y_test;

	std::vector<double>X_input;
	std::vector<double>Y_input;
	
	std::ofstream xOutput(output+"X_out.txt"), yOutput(output+"Y_out.txt"), fname(output+"filename.txt"), errors(output+"errors.txt", std::ios::out | std::ios::app);
	fname << filename;
	double long avargeError = 0.0;
	myMaths::LineralEquation::loadData(X_test, Y_test, filename, per, X_input, Y_input);
	for (int i = 0; i < X_input.size();i++) {
		xOutput << X_input[i] << std::endl;
		double y = F(X_input[i], X_test, Y_test);
		yOutput << y << std::endl;
		avargeError += abs(Y_input[i] - y);
	}
	avargeError /= X_input.size();
	std::cout << "Avarge error: " << avargeError << std::endl;
	errors << "LaGrange\t" << filename << "\t" << avargeError <<  "\t" << "one per " << per << " points" << std::endl;
}
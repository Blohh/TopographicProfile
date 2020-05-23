#pragma once
#include "Matrix.h"
#include "Vector.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
const std::string output = "../output/";
namespace myMaths {
	const std::string path = "data/";
	static class LineralEquation
	{
		static unsigned int GaussSeidleIterations;
		static unsigned int JacobiIterations;
		static double GaussSeidleTime;
		static double JacobiTime;
		static double LUTime;
	public:
		static Matrix generateEquation(int a1, int a2, int a3, int N);
		static Vector generateVector(int N, int f);
		static Vector Jacobi(const Matrix& A, const Vector& b);
		static Vector GaussSeidle(const Matrix& A, const Vector& b);
		static Vector Gauss(const Matrix& A, const Vector& b);
		static unsigned int getJacobiIterations();
		static unsigned int getGaussSeidleIterations();
		static double getGaussSeidleTime();
		static double getJacobiTime();
		static double getLUTime();
		static void getLUMatrixes(const Matrix& A, Matrix& L, Matrix& U);
		static Vector LUFactorization(const Matrix& A, const Vector& b);
		static Vector FowardSubstitution(const Matrix& L, const Vector& b);
		static Vector BackSubstitution(const Matrix& U,const Vector& y);
		static double LaGrangeInterpolation(double xi, const std::vector<double>& x, const std::vector<double>&y);
		static void loadData(std::vector<double>& x, std::vector<double>& y, std::string filename, int interval, std::vector<double>& xin, std::vector<double>& yin);
		static void generateMatrix(Matrix& A, Vector& b, Vector& x, std::vector<double>& _x, std::vector<double>& _y, int n);
		static void Pivoting(Matrix& A, Vector& b, int N);
		static double SplineInterpolation(double _x, std::vector<double>& x, std::vector<double>& y);
	};
}



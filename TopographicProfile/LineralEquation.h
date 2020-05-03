#pragma once
#include "Matrix.h"
#include "Vector.h"
namespace myMaths {
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
	};
}



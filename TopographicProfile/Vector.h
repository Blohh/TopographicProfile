#pragma once
#include <vector>
#include <exception>
#include <iostream>
namespace myMaths {
	class Vector
	{
		friend class Matrix;
		friend class LineralEquation;
	public:
		Vector(int size);
		Vector(std::vector<double> vt);
		~Vector();
		void zeros();
		void ones();
		int getSize() const;
		void swap(int first, int second);
		double norm() const;
		Vector copy() const;
		Vector& operator=(const Vector& copied);
		myMaths::Vector& operator=(const std::vector<double> vector);
		Vector operator+(const Vector& copied) throw();
		Vector operator-(const Vector& copied) throw();
		Vector operator+(const double added);
		Vector operator-(const double subbed);
		Vector operator*(const double subbed);
		friend std::ostream& operator<<(std::ostream& stream, const Vector& vt);
	protected:
		std::vector<double> vector;
	private:
		void add(const Vector& b);
		void add(const double b);
		void sub(const Vector& b);
		void multiple(const double b);
		void sub(const double b);

	};
}


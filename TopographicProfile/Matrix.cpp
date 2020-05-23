#include "Matrix.h"

myMaths::Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for (int i = 0; i < rows; i++) this->matrix[i].resize(cols);
}

myMaths::Matrix::Matrix(std::vector<std::vector<double>> mat)
{
	this->rows = mat.size();
	this->cols = mat[0].size();
	this->matrix.resize(rows);
	for (int i = 0; i < this->rows; i++) {
		this->matrix[i].resize(this->cols);
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] = mat[i][j];
	}
}

myMaths::Matrix::~Matrix()
{
	for (int i = 0; i < this->rows; i++) this->matrix[i].~vector();
	this->matrix.~vector();
}
int myMaths::Matrix::getRows() const
{
	return this->rows;
}

int myMaths::Matrix::getCols() const
{
	return this->cols;
}
myMaths::Matrix myMaths::Matrix::copy() const{
	Matrix mat = Matrix(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) mat.matrix[i][j] = this->matrix[i][j];
	}
	return mat;
}

myMaths::Matrix myMaths::Matrix::diag()
{
	Matrix mat = this->copy();
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j <this->cols; j++) if(i != j) mat.matrix[i][j] = 0;
	}
	return mat;
}

myMaths::Matrix myMaths::Matrix::upperTriangle()
{
	Matrix mat = this->copy();
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++)  if (j - i - 1 <= 0) mat.matrix[i][j] = 0;
	}
	return mat;
}

myMaths::Matrix myMaths::Matrix::lowerTriangle()
{
	Matrix mat = this->copy();
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++)  if (j - i - 1 >= 0) mat.matrix[i][j] = 0;
	}
	return mat;
}

void myMaths::Matrix::zeros()
{
	for (int i = 0; i < this->rows; i++) 
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] = 0;
}

void myMaths::Matrix::ones()
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] = 1;
}

void myMaths::Matrix::swapRows(int first, int second)
{
	for (int i = 0; i < this->getRows(); i++)
		std::swap(this->matrix[first][i], this->matrix[second][i]);
}

myMaths::Matrix& myMaths::Matrix::operator=(const myMaths::Matrix& copied)
{
	this->matrix.resize(copied.getCols());
	for (int i = 0; i < copied.getRows(); i++) {
		this->matrix[i].resize(copied.getCols());
		for (int j = 0; j < copied.getCols(); j++) this->matrix[i][j] = copied.matrix[i][j];
	}
	return *this;
}

myMaths::Matrix& myMaths::Matrix::operator=(const std::vector<std::vector<double>> mat)
{
	this->rows = mat.size();
	this->cols = mat[0].size();
	this->matrix.resize(rows);
	for (int i = 0; i < this->rows; i++) {
		this->matrix[i].resize(this->cols);
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] = mat[i][j];
	}
	return *this;
}

myMaths::Matrix myMaths::Matrix::operator+(const Matrix& added) const throw()
{
	if (this->rows != added.getRows() || this->cols != added.getCols()) throw "Wrong size of operators in matrix addition!";
	Matrix mt = this->copy();
	mt.add(added);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator-(const Matrix& subbed) const throw()
{
	if (this->rows != subbed.getRows() || this->cols != subbed.getCols()) throw "Wrong size of operators in matrix substitution!";;
	Matrix mt = this->copy();
	mt.sub(subbed);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator+(const double added) const
{
	Matrix mt = this->copy();
	mt.add(added);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator-(const double subbed) const throw()
{
	Matrix mt = this->copy();
	mt.sub(subbed);
	return mt;
}

myMaths::Matrix myMaths::Matrix::operator*(const double multication) const
{
	Matrix mt = this->copy();
	mt.multiple(multication);
	return mt;
}

myMaths::Vector myMaths::Matrix::operator*(const Vector& multiplied) const throw()
{
	if (this->cols != multiplied.getSize()) throw "Wrong size of operators in matrix and vector multiplication!";;
	Vector vt = Vector(multiplied.getSize());
	vt.zeros();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++) 
			vt.vector[i] += this->matrix[i][j] * multiplied.vector[j];
	}
	return vt;
}

myMaths::Matrix myMaths::Matrix::operator*(const Matrix& multiplied) const throw()
{
	if (this->cols != multiplied.rows) throw "Wrong size of operators in matrixes multiplication!";;
	Matrix mat = this->copy();
	mat.multiple(multiplied);
	return mat;
}

void myMaths::Matrix::add(const Matrix& B)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] += B.matrix[i][j];
}

void myMaths::Matrix::add(const double b)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] += b;
}

void myMaths::Matrix::sub(const Matrix& B)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] -= B.matrix[i][j];
}

void myMaths::Matrix::sub(const double b)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] -= b;
}

void myMaths::Matrix::multiple(const double b)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++) this->matrix[i][j] *= b;
}

myMaths::Matrix myMaths::Matrix::multiple(const Matrix& B)
{
	Matrix mat = Matrix(this->rows, B.cols);
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++) {
			for (int k = 0; k < this->cols; k++) {
				mat.matrix[i][j] += this->matrix[i][k] * B.matrix[k][j];
			}
		}
	}
	return mat;
}

std::ostream& myMaths::operator<<(std::ostream& stream, const Matrix& mat)
{
	int j = 0;
	for (int i=0; i < mat.getRows(); i++) {
		if (i == 0) stream << " [ ";
		else if (i < mat.getRows() - 1) std::cout << " | ";
		else std::cout << " [ ";
		for (j = 0; j < mat.getCols() - 1; j++) stream << mat.matrix[i][j] << ", ";
		stream << mat.matrix[i][j];
		if (i == 0) stream << " ]\n";
		else if (i < mat.getRows() - 1) std::cout << " |\n";
		else std::cout << " ]\n";
	}
	return stream;
}

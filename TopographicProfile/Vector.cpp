#include "Vector.h"
#include <vector>
#include <exception>
#include <iostream>

myMaths::Vector::Vector(int size)
{
	this->vector.resize(size);
}

myMaths::Vector::Vector(std::vector<double> vt)
{
	this->vector.resize(vt.size());
	for (int i = 0; i < vt.size(); i++) this->vector[i] = vt[i];
}

myMaths::Vector::~Vector() {
	this->vector.~vector();
}

void myMaths::Vector::zeros() {
	for (int i = 0; i < this->vector.size(); i++) vector[i] = 0;
}

void myMaths::Vector::ones() {
	for (int i = 0; i < this->vector.size(); i++) vector[i] = 1;
}

int myMaths::Vector::getSize() const
{
	return this->vector.size();
}

double myMaths::Vector::norm() const
{
	double ans = 0.0;
	for (int i = 0; i < this->vector.size(); i++) ans += vector[i] * vector[i];
	ans = sqrt(ans);
	return ans;
}

myMaths::Vector myMaths::Vector::copy() const
{
	myMaths::Vector vt = Vector(this->vector.size());
	for (int i = 0; i < this->vector.size(); i++) vt.vector[i] = this->vector[i];
	return vt;
}

void myMaths::Vector::add(const myMaths::Vector& b) {
	for (int i = 0; i < this->vector.size(); i++) {
		this->vector[i] += b.vector[i];
	}
}
void myMaths::Vector::add(const double b) {
	for (int i = 0; i < this->vector.size(); i++) {
		this->vector[i] += b;
	}
}
void myMaths::Vector::sub(const myMaths::Vector& b) {
	for (int i = 0; i < this->vector.size(); i++) {
		this->vector[i] -= b.vector[i];
	}
}

void myMaths::Vector::sub(const double b) {
	for (int i = 0; i < this->vector.size(); i++) {
		this->vector[i] -= b;
	}
}

void myMaths::Vector::multiple(const double b) {
	for (int i = 0; i < this->vector.size(); i++) {
		this->vector[i] *= b;
	}
}
myMaths::Vector& myMaths::Vector::operator=(const myMaths::Vector& copied)
{
	this->vector.resize(copied.vector.size());
	for (int i = 0; i < vector.size(); i++) this->vector[i] = copied.vector[i];
	return *this;
}

myMaths::Vector& myMaths::Vector::operator=(const std::vector<double> vector)
{
	this->vector.resize(vector.size());
	for (int i = 0; i < vector.size(); i++) this->vector[i] = vector[i];
	return *this;
}

myMaths::Vector myMaths::Vector::operator+(const myMaths::Vector& added) throw()
{
	if (this->vector.size() != added.vector.size()) throw "Wrong size of operators in vector addition!";;
	myMaths::Vector vt = Vector(this->vector.size());
	for (int i = 0; i < this->vector.size(); i++) vt.vector[i] = this->vector[i];
	vt.add(added);
	return vt;
}

myMaths::Vector myMaths::Vector::operator-(const myMaths::Vector& subbed) throw()
{
	if (this->vector.size() != subbed.vector.size()) throw "Wrong size of operators in vector substitution!";;
	myMaths::Vector vt = Vector(this->vector.size());
	for (int i = 0; i < this->vector.size(); i++) vt.vector[i] = this->vector[i];
	vt.sub(subbed);
	return vt;
}

myMaths::Vector myMaths::Vector::operator+(const double added) 
{
	myMaths::Vector vt = Vector(this->vector.size());
	for (int i = 0; i < this->vector.size(); i++) vt.vector[i] = this->vector[i];
	vt.add(added);
	return vt;
}

myMaths::Vector myMaths::Vector::operator-(const double subbed)
{
	myMaths::Vector vt = Vector(this->vector.size());
	for (int i = 0; i < this->vector.size(); i++) vt.vector[i] = this->vector[i];
	vt.sub(subbed);
	return vt;
}

myMaths::Vector myMaths::Vector::operator*(const double multiplication)
{
	myMaths::Vector vt = Vector(this->vector.size());
	for (int i = 0; i < this->vector.size(); i++) vt.vector[i] = this->vector[i];
	vt.multiple(multiplication);
	return vt;
}

std::ostream& myMaths::operator<<(std::ostream& stream, const Vector& vt)
{
	int i = 0;
	stream << "[ ";
	for (; i < vt.vector.size() - 1; i++) {
		stream << vt.vector[i] << ", ";
	}
	stream << vt.vector[i] << " ]\n";
	return stream;
}

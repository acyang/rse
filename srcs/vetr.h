/*
 * vetr.h
 *
 *  Created on: 2010/4/18
 *      Author: acyang
 */

#ifndef VETR_H_
#define VETR_H_
#include <iostream>
#include <fstream>

using namespace std;

const int lower=1;
const int upper=3;
const int dim=upper-lower+1;

class vetr
{
	double c[dim];
public:
	vetr();
	vetr(double*a);
	virtual ~vetr();
	friend vetr operator+(const vetr& v, const vetr& w);
	friend vetr operator-(const vetr& v, const vetr& w);
	friend vetr operator-(const vetr& v);
	friend vetr operator*(double a, const vetr& w);
	friend vetr operator*(const vetr& v, double b);
	friend double operator*(const vetr& v, const vetr& w);
	friend int operator==(const vetr& v, const vetr& w);
	friend int operator!=(const vetr& v, const vetr& w);
	vetr& operator+=(const vetr& w);
	vetr& operator-=(const vetr& w);
	vetr& operator*=(double b);
	double& operator[](int i);
	operator double() const;
	friend istream& operator>>(istream& cin, vetr& v);
	friend ostream& operator<<(ostream& cout, const vetr& v);
	friend ofstream& operator<<(ofstream& fout, const vetr& v);
};

#endif /* VETR_H_ */

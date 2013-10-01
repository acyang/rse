/*
 * vetr.cpp
 *
 *  Created on: 2010/4/18
 *      Author: acyang
 */

#include <cstdlib>
#include <cmath>
#include "vetr.h"

vetr::vetr() {
	// TODO Auto-generated constructor stub
	for(int i=0;i<dim;i++)
		c[i]=0.0;
}

vetr::vetr(double*a) {
	// TODO Auto-generated constructor stub
	for(int i=0;i<dim;i++)
		c[i]=a[i];
}

vetr::~vetr() {
	// TODO Auto-generated destructor stub
}

vetr operator+(const vetr& v, const vetr& w) {
	vetr u;
	for(int i=0;i<dim;i++)
		u.c[i]=v.c[i]+w.c[i];
	return u;
}

vetr operator-(const vetr& v, const vetr& w) {
	vetr u;
	for(int i=0;i<dim;i++)
		u.c[i]=v.c[i]-w.c[i];
	return u;
}

vetr operator-(const vetr& v) {
	vetr u;
	for(int i=0;i<dim;i++)
		u.c[i]=-v.c[i];
	return u;
}

vetr operator*(double a, const vetr& w) {
	vetr u;
	for(int i=0;i<dim;i++)
		u.c[i]=a*w.c[i];
	return u;
}

vetr operator*(const vetr& v, double b) {
	vetr u;
	for(int i=0;i<dim;i++)
		u.c[i]=v.c[i]*b;
	return u;
}

double operator*(const vetr& v, const vetr& w) {
	double dot=0.0;
	for(int i=0;i<dim;i++)
		dot+=v.c[i]*w.c[i];
	return dot;
}

int operator==(const vetr& v, const vetr& w) {
	for(int i=0;i<dim;i++)
		if(v.c[i]!=w.c[i]) return 0;
	return 1;
}

int operator!=(const vetr& v, const vetr& w) {
	for(int i=0;i<dim;i++)
		if(v.c[i]!=w.c[i]) return 1;
	return 0;
}

vetr& vetr::operator+=(const vetr& w) {
	for(int i=0;i<dim;i++)
		c[i]+=w.c[i];
	return *this;
}

vetr& vetr::operator-=(const vetr& w) {
	for(int i=0;i<dim;i++)
		c[i]-=w.c[i];
	return *this;
}

vetr& vetr::operator*=(double b) {
	for(int i=0;i<dim;i++)
		c[i]*=b;
	return *this;
}

double& vetr::operator[](int i) {
	if(i<lower||i>upper) {
		cout<<"subacript out of range.\n";
		exit(1);
	}
	return c[i-lower];
}

vetr::operator double()const {
	double sum=0.0;
	for(int i=0;i<dim;i++)
		sum+=c[i]*c[i];
	return sqrt(sum);
}

istream& operator>> (istream& cin, vetr& v) {
	for(int i=0;i<dim;i++)
		cin>>v.c[i];
	return cin;
}

ostream& operator<< (ostream& cout, const vetr& v) {
/*	cout<<"("<<v.c[0];
	for(int i=1;i<dim;i++)
		cout<<","<<v.c[i];
	cout<<")";*/
	cout.precision(5);
	cout.setf(ios::fixed,ios::floatfield);
	for(int i=0;i<dim;i++)
	{
		cout.width(10);
		cout<<v.c[i];
	}
	return cout;
}

ofstream& operator<<(ofstream& fout, const vetr& v) {
	fout.precision(5);
	fout.setf(ios::fixed,ios::floatfield);
	for(int i=0;i<dim;i++)
	{
		fout.width(10);
		fout<<v.c[i];
	}

	return fout;
}

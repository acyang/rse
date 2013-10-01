/*
 * atom.cpp
 *
 *  Created on: 2010/4/18
 *      Author: acyang
 */

#include "atom.h"

atom::atom()
{
	// TODO Auto-generated constructor stub
	index=0;
	type=0;
	mass=0.0;
}

atom::~atom() {
	// TODO Auto-generated destructor stub
}

void atom::set_index(int i)
{
	index=i;
}

void atom::set_type(int i)
{
	type=i;
}

void atom::set_mass(double m)
{
	mass=m;
}

void atom::set_posit(double x,double y,double z)
{
	double a[dim]={x,y,z};
	//posit(x,y,z);
	posit = a;
}

void atom::set_velcy(double vx,double vy,double vz)
{
	//velcy(vx,vy,vz);
}

void atom::set_acler(double ax,double ay,double az)
{
	//acler(ax,ay,az);
}

void atom::update_posit()
{

}

void atom::update_velcy()
{

}
void atom::update_acler()
{

}
void atom::warp()
{

}

ostream& operator<<(ostream& cout, const atom& a) {
	cout.precision(5);
	cout.setf(ios::fixed,ios::floatfield);
	cout.width(30);
	cout<<a.posit;
	cout.width(3);
	cout<<a.index;
	cout.width(3);
	cout<<a.type;
	cout.width(10);
	cout<<a.mass;
	return cout;
}

ofstream& operator<<(ofstream& fout, const atom& a) {
	fout.precision(5);
	fout.setf(ios::fixed,ios::floatfield);
	fout.width(30);
	fout<<a.posit;
	fout.width(3);
	fout<<a.index;
	fout.width(3);
	fout<<a.type;
	fout.width(10);
	fout<<a.mass;
	return fout;
}

void atom::output()
{
	cout << "index=" << index << "\n"
		 << "type= " << type  << "\n"
		 << "mass= " << mass  << "\n";
}

void atom::post(int step)
{
	char filename[12];

	sprintf(filename,"data%04d.dat",step);
//	cout << filename << endl;

	ofstream fout(filename,ios::out);
	if(!fout)
	{
		cout<< "Write file error.!!" << endl;
		return;
	}
	fout << posit ;
	fout.close();
	return;
}

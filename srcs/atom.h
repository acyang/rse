/*
 * atom.h
 *
 *  Created on: 2010/4/18
 *      Author: acyang
 */

#ifndef ATOM_H_
#define ATOM_H_
#include "vetr.h"

class atom
{
	int index;
	int type;
	double mass;
	vetr posit,velcy,acler,force;
public:
	atom();
	virtual ~atom();
	void set_index(int i);
	void set_type(int i);
	void set_mass(double m);
	void set_posit(double x,double y,double z);
	void set_velcy(double vx,double vy,double vz);
	void set_acler(double ax,double ay,double az);
	void update_posit();
	void update_velcy();
	void update_acler();
	void warp();
	friend ostream& operator<<(ostream& cout, const atom& a);
	friend ofstream& operator<<(ofstream& fout, const atom& a);
	void output();
	void post(int step);
};

#endif /* ATOM_H_ */

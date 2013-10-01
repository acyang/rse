//============================================================================
// Name        : md.cpp
// Author      : acyang
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "atom.h"

int num=10;
int step=10;

void initial(int num,atom particle[]);
void postdata(int num,int step,atom particle[]);

int main(void)
{
	atom particle[num];
	initial(num,particle);
	cout << "initial ok";

	for(int i=1;i<=step;i++)
	{
		cout << "This is step" << i << endl;
		postdata(num,i,particle);
	}
	cout << "Program End Normally!!" << endl;
	return 0;
}

void initial(int num,atom particle[])
{
	double x,y,z;
	double vx,vy,vz;
	double ax,ay,az;

	for(int j=0;j<num;j++)
	{
		srand ( time(NULL) );
		vx=2.0;
		//particle[j].set_acler(0.0,0.0,0.0);
		particle[j].set_index(j);
		switch (j%2)
		{
		case 0: particle[j].set_type(33);
				particle[j].set_mass(196.15);
				break;
		case 1: particle[j].set_type(15);
				particle[j].set_mass(14.28);
				break;
		}
		cout<<particle[j]<<endl;
	}
}

void postdata(int num,int step,atom particle[])
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
	for(int j=0;j<num;j++)
	{
		fout<<particle[j]<<endl;
	}
	fout.close();
	return;
}

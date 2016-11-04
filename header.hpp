#ifndef testIAHEADER
#define testIAHEADER

#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
using namespace std;

#define FOR(cont,max)			for(int (cont)=0;		(cont)<(int)(max);(cont)++)
#define FOR2(cont,start,max)	for(int (cont)=(start);	(cont)<(int)(max);(cont)++)
#define ABS(x)					(((x)> 0 ) ? (x) :-(x))
#define MAX(x,y)				(((x)>(y)) ? (x) : (y))
#define MIN(x,y)				(((x)<(y)) ? (x) : (y))
#define BETWEEN(x,a,b)			(((x)>=(a)) && ((x)<(b)))
#define SWAP(a,b)				int _temp_=(a);(a)=(b);(b)=_temp_;
#define RAND(max)				(rand()%(max))
#define RAND2(min,max)			((min)+(rand()%((max)-(min))))

using ii = pair<int,int>;
#define ff first
#define ss second

const double pi = acos(-1);
#define RAD(x) ((x*pi)/180.0)
#define GRAV 9.807

#define CELLS_PER_GEN 300
#define VALS_PER_CELL 2
#define CHANCE_TO_MUTATE1 2 // 2/6
#define CHANCE_TO_MUTATE2 6

const double def_vals[VALS_PER_CELL][2] = {
//	{0.0,360.0},{1.0,101.0}

	{0.1,45.01},
	{0.0,10.01}
	//{-10.0,10.01},{-10.0,10.01},{-10.0,10.01},{-10.0,10.01}
	//{  0.0, 0.01},{  0.0, 0.01},{  0.0, 0.01},{  0.0,10.01}

//	{-1000.0,1000.0},{-1000.0,1000.0},{-1000.0,1000.0},{-1000.0,1000.0},
//	{-1000.0,1000.0},{-1000.0,1000.0},{-1000.0,1000.0},{-1000.0,1000.0}

//	{    0.0,   0.0},{    0.0,   0.0},{   45.0,  45.0},{      0,     0},
//	{    0.0,   0.0},{    0.0,   0.0},{    0.0,   0.0},{   GRAV,  GRAV}
};

struct cell{
	vector<double> vals;
	double fitness;
	cell(vector<double>);
	cell();
	void mix(cell,cell);
	void mutate();
	void initRAND();
	bool operator<(const cell&) const;
	void print();
	void test();
};



double random_double(double,double);
#endif
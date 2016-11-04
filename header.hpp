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

#define CELLS_PER_GEN 30
#define VALS_PER_CELL 2
#define CHANCE_TO_MUTATE1 1
#define CHANCE_TO_MUTATE2 2

const int def_vals[VALS_PER_CELL][2] = {
	{0,360},{1,101}
};

struct cell{
	vector<int> vals;
	double fitness;
	cell(vector<int> v):vals{v}{}
	cell(){
		initRAND();
	}
	void mix(cell a,cell b){
		FOR(i,VALS_PER_CELL){
			if(RAND(2))	vals[i]=a.vals[i];
			else		vals[i]=b.vals[i];
		}
	}
	void mutate(){
		FOR(i,VALS_PER_CELL){
			if(RAND(CHANCE_TO_MUTATE2)<CHANCE_TO_MUTATE1)vals[i]=RAND2(def_vals[i][0],def_vals[i][1]);
		}
	}
	void initRAND(){
		vals.resize(VALS_PER_CELL);
		FOR(i,VALS_PER_CELL){
			vals[i]=RAND2(def_vals[i][0],def_vals[i][1]);
		}
	}
	bool operator<(const cell &other) const{
		return fitness<other.fitness;
	}
	void print(){
		FOR(i,VALS_PER_CELL){
			if(i)printf("|");
			printf("%4d",vals[i]);
		}
		printf(" -> %.02lf\n",fitness);
		fflush(stdout);
	}
	void test();
};
#endif
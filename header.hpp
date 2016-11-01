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
#define RAND2(min,max)			(min)+(rand()%((max)-(min)))

#define GENES_POR_GER 10
#define VALS_POR_GENE 6
#define MUTS_POR_GER 2

const int def_vals[VALS_POR_GENE][2] = {{-1000,1000},{-1000,1000},{-1000,1000},{-1000,1000},{0,1},{0,1}};

struct genes{
	int vals[VALS_POR_GENE];
	long long int result;
	genes(int v[VALS_POR_GENE]){
		FOR(i,VALS_POR_GENE){
			vals[i]=v[i];
		}
	}
	genes(){
		initRAND();
	}
	void randomize(genes a,genes b){
		FOR(i,VALS_POR_GENE){
			if(RAND(2))	vals[i]=a.vals[i];
			else			vals[i]=b.vals[i];
		}
		set<int> muts;
		while(muts.size()<MUTS_POR_GER)muts.insert(RAND(VALS_POR_GENE));
		for(auto i:muts){
			vals[i]=RAND2(def_vals[i][0],def_vals[i][1]);
		}
	}
	void initRAND(){
		FOR(i,VALS_POR_GENE){
			vals[i]=RAND2(def_vals[i][0],def_vals[i][1]);
		}
	}
	bool operator<(const genes &other) const{
		return result>other.result;
	}
	void print(){
		FOR(i,VALS_POR_GENE){
			if(i)printf("|");
			printf("%d",vals[i]);
		}
		printf(" -> %lld\n",result);
		fflush(stdout);
	}
};

void test(genes&);
#endif
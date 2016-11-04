#include "header.hpp"

cell::cell(vector<double> v):vals{v}{}

cell::cell(){
	initRAND();
}

void cell::mix(cell a,cell b){
	FOR(i,VALS_PER_CELL){
		if(RAND(2))	vals[i]=a.vals[i];
		else		vals[i]=b.vals[i];
	}
}

void cell::mutate(){
	FOR(i,VALS_PER_CELL){
		if(RAND(CHANCE_TO_MUTATE2)<CHANCE_TO_MUTATE1){
			if(RAND(2))	vals[i]=random_double(def_vals[i][0],vals[i]);
			else		vals[i]=random_double(vals[i],def_vals[i][1]);
		}
	}
}

void cell::initRAND(){
	vals.resize(VALS_PER_CELL);
	FOR(i,VALS_PER_CELL){
		vals[i]=random_double(def_vals[i][0],def_vals[i][1]);
	}
}

bool cell::operator<(const cell &other) const{
	return fitness<other.fitness;
}

void cell::print(){
	FOR(i,VALS_PER_CELL){
		if(i)printf("|");
		printf("%11.4lf",vals[i]);
	}
	printf(" -> %.02lf",fitness);
	fflush(stdout);
}

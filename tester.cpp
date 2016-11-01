#include "header.hpp"

void test(cell &cur){
	cur.fitness=0;
	FOR(i,VALS_PER_CELL)cur.fitness+=cur.vals[i];
}

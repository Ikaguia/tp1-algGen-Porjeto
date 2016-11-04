#include "header.hpp"

void cell::test(){
	int ang=vals[0];
	int vel=vals[1];
	if(ang>180)fitness=0;
	else fitness=(vel*vel*(sin(RAD(2*ang))))/9.807;
}

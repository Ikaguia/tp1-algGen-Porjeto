#include "header.hpp"

void cell::test(){
	if(vals[0]>=180)fitness=0;
	else if(vals[0]==90 || vals[0]==0)fitness=0;
	else{
		int ang=vals[0];
		ang = (ang>90)?180-ang:ang;
		ang = (ang>45)?90-ang:ang;
		fitness=ang*vals[1];
		if(vals[0]>90)fitness*=-1;
	}
}

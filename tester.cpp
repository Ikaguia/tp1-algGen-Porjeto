#include "header.hpp"

//get max throw distance with vals[0] = angle(0,360) and vals[1] = velocity(1,101)
/*void cell::test(){
	int ang=vals[0];
	int vel=vals[1];
	if(ang>180)fitness=0;
	else fitness=(vel*vel*(sin(RAD(2*ang))))/9.807;
}*/


//try to hit x targets using vals[] as the values for the mathematical functions
#define N_OF_TARGETS 10
#define MAX_DIST 1000
#define MAX_HEIGHT 10

//height is currently being ignored
void calcAngVel(int dist,int height,double &ang,double &vel,vector<double> vals){
	ang = vals[0];
	while(ang>360)ang-=360;
	while(ang<  0)ang+=360;
	vel = sqrtl(dist*vals[1]);
}

void cell::test(){
	double ang,vel;
	fitness = 0;
	FOR(i,N_OF_TARGETS){
		//generate the targets
		int dist=RAND2(1,MAX_DIST);
		int height=RAND2(0,MAX_HEIGHT);

		calcAngVel(dist,height,ang,vel,vals);
		double range = (vel*vel*(sin(RAD(2*ang))))/GRAV;
		if(ang>180)fitness+=dist;
		else fitness += ABS(dist-range);
	}
	fitness*=-1;
}

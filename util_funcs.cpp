#include "header.hpp"

double random_double(double a,double b){
	if(a==b)return a;
/*	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(a,b);
	return dis(gen);*/
	int upper=1000*a;
	int lower=1000*b;
	return RAND2(upper,lower)/1000.0;
}

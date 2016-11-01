#include "header.hpp"

/*int calcState(genes &cur,int front,int curState){/
	return -1+(cur.vals[0]*curState)+cur.vals[1]-((cur.vals[2]/(front+2))&cur.vals[3])%3;
}

void test(genes &cur){
	//cout << "batata in" << endl;
	int curState=0,moves=0;
	queue<int> fila;
	FOR(i,10)fila.push(0);
	cur.result=0;
	while(1){
		if((fila.front()==curState && fila.front()==1) || (fila.front()!=curState && fila.front()==-1) || cur.result>100000000)break;
		fila.pop();
		fila.push(RAND2(-1,2));
		if(curState!=calcState(cur,fila.front(),curState)){
			moves++;
		}
		curState=calcState(cur,fila.front(),curState);
		cur.result+=10;
	}
	cur.result*=moves;
	//cout << "batata out" << endl;
}*/

#define POT2(a) ((a)*(a))
#define POT3(a) ((a)*(a)*(a))

void test(genes &cur){
	cur.result = ((long long int)POT2(cur.vals[0]) + (long long int)POT2(cur.vals[1]) - (long long int)POT2(cur.vals[2]))*(long long int)POT3(cur.vals[3]);
}
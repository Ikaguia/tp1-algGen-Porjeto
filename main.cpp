#include "header.hpp"

bool compFunc(const pair<int,int> a,const pair<int,int> b){
	return a.first>b.first;
}

int main(){
	srand(time(NULL));
	vector<cell> cur(CELLS_PER_GEN),prev(CELLS_PER_GEN);
	int cont=0;
	while(1){
		cont++;
		//calculate fitness
		vector<pair<int,int> > results;
		FOR(i,CELLS_PER_GEN){
			test(cur[i]);
			results.push_back(pair<int,int>(cur[i].fitness,i));
			sort(results.begin(), results.end(),compFunc);
			system("clear||cls");
			printf("Generation %d:\n",cont);
			for(auto i:results){
				printf("Cell %2d: ",i.second);
				cur[i.second].print();
			}
			fflush(stdout);
			usleep(50000);
		}
		usleep(500000);
		sort(cur.begin(), cur.end());
		prev=cur;
		//generate new generation based on fitness, better fitness means better chance to mate
		FOR(i,CELLS_PER_GEN-2){
			int a,b;
			while(1){
				a=(int)sqrt(RAND(CELLS_PER_GEN*CELLS_PER_GEN));
				b=(int)sqrt(RAND(CELLS_PER_GEN*CELLS_PER_GEN));
				if(a!=b)break;
			}
			//cout << i << " = " << a << " + " << b << endl;
			cur[i].mix(prev[a],prev[b]);
		}
		//make mutations
		FOR(i,CELLS_PER_GEN-2){
			cur[i].mutate();
		}
	}
	return 0;
}
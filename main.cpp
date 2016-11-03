#include "header.hpp"

bool compFunc(const ii a,const ii b){
	return a.ff>b.ff;
}

int main(){
	srand(time(NULL));
	vector<cell> cur(CELLS_PER_GEN),prev(CELLS_PER_GEN);
	int cont=0;
	while(1){
		cont++;
		//calculate fitness
		vector<ii > results;
		FOR(i,CELLS_PER_GEN){
			cur[i].test();
			results.push_back(ii(cur[i].fitness,i));
			sort(results.begin(), results.end(),[](const ii a,const ii b){return a.ff>b.ff;});
			system("clear||cls");
			printf("Generation %d:\n",cont);
			for(auto i:results){
				printf("Cell %2d: ",i.ss);
				cur[i.ss].print();
			}
			fflush(stdout);
			usleep(50000);
		}
		usleep(500000);
		sort(cur.begin(), cur.end());
		prev = cur;
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
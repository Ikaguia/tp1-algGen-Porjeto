#include "header.hpp"

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
			printf("Generation %3d:\n",cont);
			printf("Testing cell %3d/%3d\n",i,CELLS_PER_GEN);
			int temp=0;
			for(auto i:results){
				if(temp++>30)break;
				printf("Cell %3d: ",i.ss);
				cur[i.ss].print();
				if(i.ss==CELLS_PER_GEN-2 || i.ss==CELLS_PER_GEN-1)printf("<<---");
				printf("\n");
			}
			fflush(stdout);
			//usleep(50000);
		}
		usleep(5000);
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
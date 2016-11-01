#include "header.hpp"


int main(){
	srand(time(NULL));
	vector<genes> v(GENES_POR_GER);
	int cont=0;
	while(1){
		cont++;
		FOR(i,GENES_POR_GER)test(v[i]);
		if((cont%10)==0 || cont==1){
			system("clear||cls");
			printf("Geração %d:\n",cont);
			FOR(i,GENES_POR_GER){
				printf("Gene %2d: ",i+1);
				v[i].print();
			}
			fflush(stdout);
			usleep(1000000);
		}
		else{
			cout << ".";
			fflush(stdout);
			usleep(1);
		}
		sort(v.begin(), v.end());
		FOR2(i,2,GENES_POR_GER)v[i].randomize(v[0],v[1]);
	}
	return 0;
}
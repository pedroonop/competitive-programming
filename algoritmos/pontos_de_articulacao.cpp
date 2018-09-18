/*
* @Author: pedrotorres
* @Date:   2018-04-24 19:29:47
* @Last Modified by:   pedrotorres
* @Last Modified time: 2018-09-06 09:27:30
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector < vector <int> > vvi;
typedef vector <int>  vi;

vvi g;
vi menor, nivel, pai, art;
int cont;

set<int> arts_;

void articulacao(int i){     
	int nfilhos = 0;

	nivel[i] = menor[i] = cont++;

	for (int j = 0;j< g[i].size();j++){
		int u = g[i][j];

		if (nivel[u] == -1){
			nfilhos++;
			pai[u]=i;
			articulacao(u);
			menor[i] = min( menor[i], menor[u]);

			if (nivel[i] != 1 && menor[u] >= nivel[i]) { 
				arts_.insert(i);
				art[i] = 1;
			}

		}
		else if (pai[i] != u){
			if(nivel[u] < menor[i]) menor[i] = nivel[u]; 
		}                  
	}

	if (nivel[i] == 1 && nfilhos > 1) { 
		arts_.insert(i);
		art[i] = 1;
	}
}

int main(){
	int n,m;
	int teste = 1;
	cin >> n >> m;
	
	while(!(n == 0 && m == 0)){
		g.resize(n + 1);
		
		for(int i = 0; i <= n; i++) g[i].clear();
		
		for(int i = 0; i < m; i++){
			int a,b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		cont = 1;
		arts_.clear();
		menor.assign(n + 1, -1);
		pai.assign(n + 1, -1);
		nivel.assign(n + 1, -1);
		art.assign(n + 1,  0);
		articulacao(1);

		set<int>::iterator it;

		printf("Teste %d\n" ,teste);

		int arts_size = arts_.size();

		if(arts_size){
			it = arts_.begin();
			for(int i = 0; i < arts_size - 1; i++){
				printf("%d ", *it);
				it++;
			}		
			printf("%d" ,*it);	
		}
		else{
			printf("nenhum");
		}
		printf("\n\n");
		scanf("%d %d" ,&n ,&m);
		teste++;
	}
	return 0;
}
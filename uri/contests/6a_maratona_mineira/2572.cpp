#include <bits/stdc++.h>

using namespace std;
#define ii pair <int, int>
#define MAXN 1000
#define go(i,n) for (int i = 1; i <= (int)n; i++)
#define INF 0x3f3f3f3f

ii linhas [MAXN];
ii colunas [MAXN];
int matriz [MAXN][MAXN];
int vetor[6];
int main (){
	
	int n, m, k, jogada;
	char op;
	scanf ("%d %d %d", &n, &m, &k);
	go(i,MAXN){
		linhas[i].second = -INF;
		colunas[i].second = -INF;
		linhas[i].first = 0;
		colunas[i].first = 0;
	}
	for (int i = 0; i < k; i++){
		scanf (" %c", &op);
		scanf ("%d", &jogada);
		if (op == 'L'){
			linhas[jogada] = ii((((i)%4)+1), i);
		}
		else{
			colunas[jogada] = ii((((i)%4)+1),i);
		}
		//printf ("jogador = %d\n", ((i-1)%4)+1);
	}
	
	go (i,n){
		go (j,m){
			//printf ("linha %d  coluna %d\n", i, j);
			//printf ("l.first %d   l.second %d   c.first %d   c.second %d\n", linhas[i].first, linhas[i].second, colunas[j].first, colunas[j].second);
			if (linhas[i].second > colunas[j].second){ vetor[linhas[i].first]++;/*printf ("a -> jogador %d", linhas[i].first);*/}
			else {vetor[colunas[j].first]++;/*printf ("b -> jogador %d", colunas[j].first);*/}
			//printf ("\n");
		}
	}
	
	printf ("R%d H%d C%d P%d\n", vetor[1], vetor[2], vetor[3],vetor[4]);
	return 0;
}

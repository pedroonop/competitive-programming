#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int v[101];

int main (){
	int n,c,k;
	while (scanf ("%d %d %d", &n, &c, &k) == 3){
		if (n == 0) break;
		int menor = INF;
		memset (v, 0, sizeof v);
		for (int j = 0; j < n; j++){
			for (int i = 0; i < c; i++){
				int a;
				scanf ("%d", &a);
				v[a]++;
			}
		}
		int qtd = 0;
		for (int i = 1; i <= k; i++){
			menor = min(menor, v[i]);
		}
		for (int i = 1; i <= k; i++){
			if (v[i] == menor) qtd++;
		}
		for (int i = 1; i <= k; i++){
			if (v[i] == menor && qtd > 1){
				printf ("%d ", i);
				qtd--;
			}
			else if (v[i] == menor){
				printf ("%d", i);
			}
		}
		printf("\n");
		
	}
	
	
	return 0;
}

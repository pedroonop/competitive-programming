#include <bits/stdc++.h>
#define MAXN 170000
#define INF 0x3f3f3f3f
#define lld long long int
int vetor[MAXN];
int dp [MAXN];
int main (){
	int n,k, indice;
	lld menor = INF;
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf ("%d", &vetor[i]);
	}
	
	for (int i = 0; i < k; i++){
		dp[0] += vetor[i];
	}
	indice = 0;
	menor = dp[0];
	//printf ("%d\n", dp[0]);
	for (int i = 1; i < n-k+1; i++){
		dp[i] = dp[i-1] + (vetor[i+k-1]-vetor[i-1]);
		if (dp[i] < menor){
			menor = dp[i];
			indice = i;
			//printf ("a\n");
		}
		//printf ("dp = %d\n", dp[i]);
	}
	printf ("%d\n", indice+1);
	return 0;
}

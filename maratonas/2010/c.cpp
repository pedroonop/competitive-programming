#include <bits/stdc++.h>
#define ii pair <int, int>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define ZERO 16000
#define MAXV 32010
#define MAXN 50
using namespace std;
int n, f;

int memo[MAXN][MAXV];
int vertice[2][MAXN];
int vetor[MAXN];
int dp (int i, int valor){
	if (i == n){return valor == f;}
	//if (memo[i][valor] != -1) return memo[i][valor];
	
	vertice[0][i] = vertice[0][i] || dp(i+1, valor+vetor[i]);
	vertice[1][i] +=  dp(i+1, valor-vetor[i]);
	//if (i == 1) printf ("valor = %d x = %d\n", valor-ZERO, vertice[1][i]);
	return memo[i][valor] = vertice[0][i] || vertice[1][i];
}


int main (){
	scanf ("%d %d", &n, &f);
	memset (memo, -1, sizeof(memo));
	f += ZERO;
	go(i,n){
		scanf ("%d", &vetor[i]);
	}
	if (!dp(0,ZERO)){ printf("*\n");}
	else{
		go(i,n){
			if (vertice[0][i] && vertice[1][i]) printf ("?");
			else if (vertice[0][i]) printf ("+");
			else if (!vertice[0][i] && vertice[1][i]) printf ("-");
		}
		printf ("\n");
	}
	return 0;
}

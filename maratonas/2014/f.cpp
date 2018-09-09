#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define mod (int) 1e4

struct Matriz {
	int matriz[100][100];
	int *operator[](int i){
		return matriz[i];
	}
};

Matriz matriz;

Matriz multMatriz (Matriz a, Matriz b, int n){
	Matriz aux;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			aux.matriz[i][j] = 0;
			for (int k = 0; k < n; k++){
				aux.matriz[i][j] = ((aux.matriz[i][j]%mod) + ((a.matriz[i][k]%mod) * (b.matriz[k][j]%mod))%mod)%mod; 	
			}
		}
	}
	return aux;
}

Matriz expMat (Matriz base, int expoente, int n){
	Matriz aux;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (i == j) aux.matriz[i][j] = 1;
			else aux.matriz[i][j] = 0;
		}
	}
	
	while (expoente){
		if (expoente % 2 == 1)
			aux = multMatriz(aux, base, n);
		base = multMatriz (base, base, n);
		expoente /= 2;
	}
	return aux;
}


int main(){
	int n, l;
	while (scanf ("%d %d", &n, &l) == 2){
		int partida, chegada;
		scanf ("%d %d", &partida, &chegada);
		partida--;
		chegada--;
		memset (matriz.matriz, 0, sizeof matriz.matriz);
		int a, b, c, d;
		for (int i = 0; i < n; i++){
			scanf ("%d %d %d %d", &a, &b, &c, &d);
			a--;
			b--;
			c--;
			d--;
			matriz[i][a]++;
			matriz[i][b]++;
			matriz[i][c]++;
			matriz[i][d]++;
		}
		matriz = expMat(matriz, l, n);
		printf("%d\n", matriz[partida][chegada]);
	}
	return 0;
}
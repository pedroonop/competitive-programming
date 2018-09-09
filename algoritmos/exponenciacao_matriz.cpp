#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define mod (int) 1e4


struct Matriz {
	int matriz[100][100];
	int *operator[](int i){
		return matriz[i];
	}
};


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


int main () {
	Matriz matriz;
	int n, l,aux, u, v;
	while (scanf ("%d %d", &n, &l) != EOF){
		scanf ("%d %d", &u, &v);
		
		u--;
		v--;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				matriz.matriz[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 4; j++){
				scanf ("%d", &aux);
				matriz.matriz[i][aux-1]++;
			}
		}
		Matriz resultado;
		resultado = expMat(matriz,l, n);
		
		
		
		
		printf ("%d\n", resultado.matriz[u][v]);
	}
	return 0;
}

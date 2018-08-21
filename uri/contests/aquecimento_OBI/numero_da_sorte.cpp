#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 305100
#define vi vector <int>
#define ii pair <int,int>
#define iii pair <ii,int>
#define vii vector<ii>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define lld long long int
#define iic pair <ii, char>
using namespace std;
int vetor[MAXN];

int main () {
	int n;
	while (scanf ("%d", &n) == 1){
		for (int i = 0; i < n; i++){
			scanf ("%d", &vetor[i]);
		}
		int x;
		scanf ("%d", &x);
		go(i,n){
			if (vetor[i] == x) {
				x = i+1;
				break;
			}
		}
		int eliminado = 2;
		while (1){
			if (x < eliminado){
				//printf ("x = %d  eliminado = %d\n", x, eliminado);
				printf ("Y\n");
				break;
			}
			if (x%eliminado == 0){
				printf ("N\n");
				break;
			}
			x -= x/eliminado;
			eliminado++;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
#define MAXN 100010
#define go(i,n) for (int i = 0; i < (int) n; i++)
//int vetor[MAXN];
int indice (int n){
	if (n == 100) return 2;
	if (n == 50) return 1;
	return 0;
}
int val[] = {25,50,100};
int main (){
	int n, a;
	scanf ("%d", &n);
	int vetor[3];
	memset (vetor,0, sizeof(vetor));
	int x = 0;
	go(i,n){
		scanf ("%d", &a);
		vetor[indice(a)]++;
		x = indice(a);
		a -= 25;
		while (a > 0){
			//printf ("%d\n", x);
			if (a >= val[x]  && vetor[x]){
				a -= val[x];
				vetor[x]--;
			}
			else{
				x--;
			}
			if (x < 0 && a){
				printf ("NO\n");
				return 0;
			}
		}
	}
	printf ("YES\n");
	return 0;
}

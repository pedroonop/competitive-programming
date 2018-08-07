#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
#define MAXN 110
#define go(i,n) for (int i = 0; i < (int) n; i++)
int vetor[MAXN];


int main (){
	int n;
	scanf ("%d", &n);
	go(i,n){
		scanf ("%d", &vetor[i]);
	}
	sort (vetor, vetor+n);
	int ans = 0;
	for (int i = 0; i < n; i++){
			if (ans * (vetor[i]+1) <= i){
				ans++;
			}
		}
	printf ("%d\n", ans);
	return 0;
}

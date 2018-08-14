#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAXN 9
int valores[MAXN];
int main (){
	int n;
	while (scanf ("%d", &n) == 1){
		if (n == 0) return 0;
		for (int i = 0; i < n; i++){
			scanf ("%d", &valores[i]);
		}
		sort (valores, valores+n);
		do{
			for (int i = 0; i < n; i++){
				//printf ("%d ", valores[i]);
			}
			//printf ("\n");
		}
		while (next_permutation(valores, valores+n));
		printf ("\n");
	}
	return 0;
}

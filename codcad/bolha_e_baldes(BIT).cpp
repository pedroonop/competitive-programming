#include <bits/stdc++.h>

int tree[1000005];
int vetor[1000005];
int n;
int busca_maiores (int i){
	int ans = 0;
	for (; i; i -= (i&-i)){
		ans += tree[i];
	}
	
	return ans;
}

void update (int i, int x){
	for (; i <= n+2; i += (i&-i))
		tree[i] += x;
}


int main (){
	while (true){
		scanf ("%d", &n);
		if (n == 0) break;
		memset (tree, 0, sizeof (tree));
		memset (vetor, 0, sizeof (vetor));
		long long int ans = 0;
		for (int i = 1; i <= n; i++){
			scanf ("%d", &vetor[i]);
		}
		for (int i = n; i >= 1; i--){
			ans += (busca_maiores(vetor[i]-1));
			update (vetor[i], 1);
		}
		if (ans % 2 == 0) printf ("Carlos\n");
		else printf ("Marcelo\n");
	}
	return 0;
}

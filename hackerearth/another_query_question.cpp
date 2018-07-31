#include <bits/stdc++.h>
#define MAXN 100100
#define ZERO 1000000000
using namespace std;

//bitset <2000000000> vetor;
//int bit [2000000000];
//void update (
unsigned int bit[MAXN];


void update (int i, int valor){
	for (; i <= MAXN; i += (i&-i)) bit[i] += valor;
}

unsigned int query (int i){
	unsigned int ans = 0;
	for (; i; i -= (i&-i)) ans += bit[i];
	return ans;
}


int main (){
	int n, aux, op, q;
	scanf ("%d",&n);
	map <int, int> m;
	for (int i = 0; i < n; i++){
		scanf ("%d", &aux);
		m[ZERO+aux] = 1;
	}
	scanf ("%d", &q);
	while (q--){
		scanf ("%d %d", &op, &aux);
		if (op == 1) update (aux, 1);
		else{
			unsigned int ans;
			if (aux < 0) ans = 0;
			else ans = query (aux);
			//printf ("ans = %u\n", ans);
			if (m[ZERO+aux-ans]) printf ("yes\n");
			else printf ("no\n");
		}
	}
	return 0;
}

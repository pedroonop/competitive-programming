#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 100010
#define go(i,n) for (int i = 0; i < (int) n; i++)
#define lld long long int
using namespace std;

lld bit[MAXN];


void update (int i, int val){
	for (; i <= MAXN; i += (i&-i)){
		bit[i] += val;
	}
}

int busca (int i){
	lld ans = 0;
	for (; i; i -= (i&-i)){
		ans += bit[i];
	}
	return ans;
}

int vetor[MAXN];

int main (){
	int n;
	
	while (scanf ("%d", &n) == 1){
		if (n == 0) break;
		memset (bit, 0, sizeof(bit));
		go(i,n){
			scanf ("%d", &vetor[i]);
		}
		lld ans = 0;
		for (int i = n-1; i >= 0; i--){
			ans += busca(vetor[i]);
			update (vetor[i], 1);
		}
		if (ans%2 == 1) printf ("Marcelo\n");
		else printf ("Carlos\n");
	}
	return 0;
}

#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define lld long long int
using namespace std;

vi g [1001];
int qtdArestas[1001];
int removidos[1001];
int pesos[1001];
int pesosAcumulado[1001];
priority_queue <ii, vector<ii>, greater<ii> > pq;
int main (){
	int n, m, a, b;
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf ("%d", &pesos[i]);
		
	}
	lld ans = 0;
	for (int i = 0; i < m; i++){
		scanf ("%d %d", &a, &b);
		ans += min (pesos[a], pesos[b]);
		//g[a].push_back(b);
		//g[b].push_back(a);
	}
	printf ("%lld\n", ans);
	return 0;
}

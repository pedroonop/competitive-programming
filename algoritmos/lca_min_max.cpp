#include <bits/stdc++.h>
#define lld long long int
#define ii pair<int, int>
#define vi vector<ii>
using namespace std;

//--------------------------
#define MAXL    30
#define MAXN 100010

int n;

int pai[MAXN];
int nivel[MAXN];
int ancestral[MAXN][MAXL];
lld custo[MAXN][MAXL];
int custo_pai[MAXN];
vector<ii> lista[MAXN];
lld ans = 0;

void dfs(int u){
	
	for(int i = 0;i < (int)lista[u].size();i++){
		int v = lista[u][i].first;
		
		if(nivel[v] == -1){
			pai[v] = u;
			nivel[v] = nivel[u]+1;
			custo_pai[v] = lista[u][i].second;
			dfs(v);
		}
	}
	
}

int LCA(int u, int v){
	
	if(nivel[u] < nivel[v]) swap(u, v);
	
	for(int i = MAXL-1;i >= 0;i--)
		if(nivel[u] - (1<<i) >= nivel[v]){
			ans += custo[u][i];
			u = ancestral[u][i];
		}
	
	if(u == v) {return u;}
	for(int i = MAXL-1;i >= 0;i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			ans += custo[u][i];
			ans += custo[v][i];
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	ans += custo_pai[u];
	ans += custo_pai[v];
	return pai[u];
}

int main(){
	int a;
	int b;
	while (1){
		scanf ("%d", &n);
		if (n == 0) break;
		for (int i = 0; i <= n; i++){
			lista[i].clear();
		}
		for (int i = 1; i < n; i++){
			scanf ("%d %d", &a, &b);
			lista[i].push_back(ii(a,b));
			lista[a].push_back(ii(i,b));
		}
		
		memset (nivel, -1, sizeof(nivel));
		nivel[0] = 0;
		pai[0] = 0;
		dfs(0);
		for(int i = 0;i <= n;i++){
			ancestral[i][0] = pai[i];
			custo[i][0] = custo_pai[i];
		}
		for(int j = 1;j < MAXL;j++){
			for(int i = 0;i <   n;i++){
				ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
				custo[i][j] = custo[ancestral[i][j-1]][j-1] + custo[i][j-1];
			}
		}
		int q;
		scanf ("%d", &q);
		while (q--){
			ans = 0;
			scanf ("%d %d", &a, &b);
			LCA(a,b);
			if (q) printf ("%lld ", ans);
			else printf ("%lld", ans);
		}
		printf ("\n");
	}
	return 0;
}

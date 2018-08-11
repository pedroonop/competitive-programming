#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAXN 1001

int valores[MAXN];
int dp [MAXN];
vi g[MAXN];
int seen [MAXN];

int dfs (int v){
	if (seen[v]) return dp[v];
	seen[v] = 1;
	int ans = 0;
	for (int u : g[v]){
		ans = max (ans, dfs(u));
	}
	return dp[v] = ans+valores[v];
}

int main (){
	int n, qtd,b;
	while (scanf ("%d", &n) == 1){
		if (n == 0) break;
		memset(dp, 0, sizeof(dp));
		memset(seen, 0, sizeof(seen));
		for (int z = 1; z <= n; z++){
			g[z].clear();
			scanf ("%d %d", &valores[z], &qtd);
			for (int i = 0; i < qtd; i++){
				scanf ("%d", &b);
				g[z].push_back(b);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			ans = max (ans,dfs(i)); 
		}
		printf ("%d\n", ans);
	}
	return 0;
}

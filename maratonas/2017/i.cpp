#include <bits/stdc++.h>

#define pb push_back
#define MAXN 10001

using namespace std;

typedef pair<int, int> ii;

vector<ii> g[MAXN];
int cor[MAXN];
bool folhas[MAXN];
int cofre[MAXN];
int ans = 0;
int cap = 0;

void dfs(int u){
	cor[u] = 1;
	bool folha = true;

	for (auto v : g[u]){
		if (!cor[v.first]){
			dfs(v.first);
			int m = 0;
			if ((cofre[v.first] % cap) != 0) m++;
			ans += v.second * ((cofre[v.first] / cap) + m);
			cofre[u] += cofre[v.first];
			cofre[v.first] = 0;
		}
	}
}

int main(){
	int n, u, v, w;

	scanf("%d %d" ,&n ,&cap);

	for (int i = 1; i <= n; i++){
		scanf("%d" ,&cofre[i]);
	}

	for (int i = 0; i < n - 1; i++){
		scanf("%d %d %d" ,&u ,&v ,&w);

		g[u].pb(ii(v, w));
		g[v].pb(ii(u, w));
	}

	dfs(1);

	printf("%d\n", ans * 2);

	return 0;
}
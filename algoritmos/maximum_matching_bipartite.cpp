#include <bits/stdc++.h>
#define vi vector<int>
#define MAXN 1000
#define go(i,n) for (int i = 0; i <(int) n; i++)
using namespace std;

int vis[MAXN], b[MAXN];
vector <vi> g;
bool match (int u){
	if (vis[u]) return false;
	vis[u] = 1;
	for (int v : g[u]){
		if (!b[v] or match(b[v])){
			b[v] = u;
			return true;
		}
	}
	return false;
}


int main (){
	int n, a, x,m;
	scanf ("%d %d", &n, &m);
	memset (b, 0, sizeof(b));
	g.resize(n+1);
	go(i,m){
		scanf ("%d %d", &a, &x);
		g[a].push_back(x);
		g[x].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		memset (vis,0,sizeof(vis));
		 if (match(i)){
			 ans++;
		 }
	}
	printf ("%d\n", ans);
	return 0;
}

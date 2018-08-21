/*
* @Author: Pedro Torres
* @Date:   2018-08-21 08:50:06
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-08-21 09:42:57
*/

#include <bits/stdc++.h>

#define MAXN 50501
#define MAXL 20

#define pb push_back

using namespace std;

list<int> g[MAXN];

int nivel[MAXN];
int pai[MAXN];
int ancestral[MAXN][MAXL];

// ancestral[i][j] = 2^j-esimo ancestral de i

void dfs(int u){
	list<int>::iterator it;
	for(it = g[u].begin(); it != g[u].end(); it++){
		if(nivel[*it] == -1){
			nivel[*it] = nivel[u] + 1;
			pai[*it] = u;
			dfs(*it);
		}
	}
}

int lca(int u, int v){
	if(nivel[u] < nivel[v]){
		swap(u, v);
	}

	for(int i = MAXL - 1; i >= 0; i--){
		if(nivel[u] - (1 << i) >= nivel[v]){
			u = ancestral[u][i];
		}
	}

	if(u == v){
		return u;
	}

	for(int i = MAXL - 1; i >= 0; i--){
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}

	return pai[u];
}

int LCA(int u, int v){
	
	if(nivel[u] < nivel[v]) swap(u, v);
	
	for(int i = MAXL-1;i >= 0;i--)
		if(nivel[u] - (1<<i) >= nivel[v])
			u = ancestral[u][i];
	
	if(u == v) return u;
	
	for(int i = MAXL-1;i >= 0;i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
			
	return pai[u];
}

int main(){
	int n, m;
	int u, v;

	scanf("%d %d" ,&n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d" ,&u ,&v);
		
		g[u].pb(v);
		g[v].pb(u);
	}

	for(int i = 0; i < MAXN; i++){
		pai[i] = nivel[i] = -1;
	}

	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXL; j++){
			ancestral[i][j] = -1;
		}
	}

	nivel[1] = 0;
	dfs(1);

	for(int i = 1; i <= n; i++){
		ancestral[i][0] = pai[i];
	}

	for(int j = 1; j < MAXL; j++){
		for(int i = 1; i <= n; i++){
			ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}
	}

	// distancia de um nivel u:v
	// int dist = nivel[u] + nivel[v] - 2 * nivel[lca(u, v)];
	return 0;
}
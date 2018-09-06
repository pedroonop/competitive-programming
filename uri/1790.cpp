/*
* @Author: Pedro Torres
* @Date:   2018-09-06 09:01:03
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-09-06 09:12:37
*/

#include<bits/stdc++.h>

#define MAXN 51
#define ii pair<int, int>
#define pb push_back

using namespace std;

list<int> g[MAXN];
bool color[MAXN];
int level[MAXN];
int pi[MAXN];
int low[MAXN];
set<ii> bridges;

void dfs(int u){
	static int time = 1;
	color[u] = 1; 
	level[u] = low[u] = time++;
	for (list<int>::iterator it = g[u].begin(); it != g[u].end(); it++){
		if (!color[*it]){
			pi[*it] = u;
			dfs(*it);
			low[u] = min(low[u], low[*it]);
			if (low[*it] > level[u]){
				bridges.insert(ii(*it, u));
				// bridges.insert(ii(u, *it)); (pode ser necessario depedendo do problema)
			}
		}
		else if (*it != pi[u]){
			low[u] = min(low[u], level[*it]);
		}
	}
}

int main(){
	int n, m, u, v;

	while (scanf("%d %d" ,&n ,&m) != EOF){
		for (int i = 0; i < MAXN; i++) g[i].clear();
		memset(color, 0, sizeof(color));
		memset(level, 0, sizeof(level));
		memset(pi, 0, sizeof(pi));
		memset(low, 0, sizeof(low));
		bridges.clear();

		for(int i = 0; i < m; i++){
			scanf("%d %d" ,&u ,&v);
			g[u].pb(v);
			g[v].pb(u);
		}

		dfs(1);

		printf("%d\n" ,(int) bridges.size());
	}


	return 0;
}
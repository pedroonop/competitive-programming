#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define vvii vector <vii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define MAXN 10001

vvii g;
bool color[MAXN];
int level[MAXN];
int pi[MAXN];
int low[MAXN];
set<ii> bridges;

void dfs(int u){
	static int time = 1;
	color[u] = 1; 
	level[u] = low[u] = time++;

	for (auto v : g[u]){
		if (!color[v.ff]){
			pi[v.ff] = u;
			dfs(v.ff);
			low[u] = min(low[u], low[v.ff]);
			if (low[v.ff] > level[u]){
				bridges.insert(ii(v.ff, u));
				bridges.insert(ii(u, v.ff));
			}
		}
		else if (v.ff != pi[u]){
			low[u] = min(low[u], level[v.ff]);
		}
	}
}

int indice;
bool flag = false;
map <int, int> indices_valendo;
map <int, int> valor;
int dfs_pontes(int u, int pai){
	indices_valendo[u] = indice;
	color[u] = 1;
	int cost = 0;
	//printf("%d\n" ,u);

	for (auto v : g[u]){
		if (bridges.find(ii(u,v.ff)) != bridges.end()) continue;
		if (v.ff == pai) continue;
		if (!color[v.ff]){
			cost += dfs_pontes(v.ff, u) + v.ss;
		}
		else{
			if(!flag){
				cost += v.ss;
				flag = true;
			}
		}
	}

	return cost;
}

int main(){
	g.resize(MAXN);
	int n, m, u, v, w;

	scanf("%d %d" ,&n ,&m);

	memset(color, 0, sizeof(color));
	memset(level, 0, sizeof(level));
	memset(pi, 0, sizeof(pi));
	memset(low, 0, sizeof(low));

	for (int i = 0; i < m; i++){
		scanf("%d %d %d" ,&u ,&v ,&w);
		g[u].pb(ii(v, w));
		g[v].pb(ii(u, w));	
	}
	dfs(1);
	ms(color, 0);
	indice = n;

	for(auto x : bridges){
		printf("%d %d\n", x.ff, x.ss);
	}
	printf("%lu\n", bridges.size());
	for (int i = 1; i <= n; i++){
		if (indices_valendo[i]) continue;
		for (auto v : g[i]){
			if (bridges.find(ii(i, v.ff)) == bridges.end()){
				ms(color, 0);
				cout << dfs_pontes(i, i) << endl;
				valor[indices_valendo[i]] = dfs_pontes(i,i);
				flag = false;
				indice++;
				
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if(indices_valendo.find(i) == indices_valendo.end()){
			indices_valendo[i] = i;
			valor[i] = 0;
		}
	}

	return 0;
}
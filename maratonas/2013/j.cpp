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
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define MAXN 20010
#define MAXL 25
vector<vii> g;
vector<vii> agm;
int n, m, q;



int n_lca;
int pai[MAXN];
int nivel[MAXN];
int ancestral[MAXN][MAXL];
lld custo[MAXN][MAXL];
lld custo_pai[MAXN];
vector<ii> lista[MAXN];
lld ans = INF;


void dfs(int u){
	
	for(int i = 0;i < (int)agm[u].size();i++){
		int v = agm[u][i].first;
		if (v == 0) continue;
		if(nivel[v] == -1){
			pai[v] = u;
			nivel[v] = nivel[u]+1;
			custo_pai[v] = agm[u][i].second;
			//printf("custo_pai = %d    v = %d\n", custo_pai[v], v);
			dfs(v);
		}
	}
	
}

int LCA(int u, int v){
	
	if(nivel[u] < nivel[v]) swap(u, v);
	
	for(int i = MAXL-1;i >= 0;i--)
		if(nivel[u] - (1<<i) >= nivel[v]){
			ans = min(custo[u][i], ans);
			u = ancestral[u][i];
		}
	
	if(u == v) {return u;}
	for(int i = MAXL-1;i >= 0;i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			ans = min(custo[u][i],ans);
			ans = min(custo[v][i], ans);
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	ans = min(custo_pai[u], ans);
	ans = min(custo_pai[v], ans);
	return pai[u];
}


void prim(){
	agm.resize(n + 1);
	int pi[20001];
	for (int i = 1; i <= n; i++){
		pi[i] = -1;
	}
	priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;
	pq.push(make_pair(0, ii(1, 0)));
	while (!pq.empty()){
		pair<int, ii> topo = pq.top();
		int u = topo.ss.ff;
		pq.pop();
		if (pi[u] != -1) continue;
		pi[u] = topo.ss.ss;
		agm[u].pb(ii(pi[u], -topo.ff));
		agm[pi[u]].pb(ii(u, -topo.ff));
		go (i, g[u].size()){
			int v = g[u][i].ff, w = g[u][i].ss;
			if (pi[v] == -1){
				pq.push(make_pair(w, ii(v, u)));
			}
		}
	}
}

int main(){

	while (scanf("%d %d %d", &n, &m, &q) == 3){
		g.clear();
		g.resize(n + 1);
		agm.clear();
		memset (ancestral, 0, sizeof ancestral);
		memset (custo, 0, sizeof custo);
		memset (custo_pai, 0, sizeof custo_pai);
		memset (pai, 0, sizeof pai);

		go (i, m){
			int a, b, p;
			scanf("%d %d %d", &a, &b, &p);
			g[a].pb(ii(b, -p));
			g[b].pb(ii(a, -p));
		}

		prim();
		memset (nivel, -1, sizeof(nivel));

		dfs(1);
		pai[1] = 1;
		for(int i = 1;i <= n;i++){
			ancestral[i][0] = pai[i];
			custo[i][0] = custo_pai[i];
		}
		for(int j = 1;j < MAXL;j++){
			for(int i = 1; i <= n;i++){
				ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
				custo[i][j] = min(custo[ancestral[i][j-1]][j-1], custo[i][j-1]);
				//printf("%d\n", custo[i][j] );
			}
		}

		go(i,q){
			ans = INF;
			int a, b;
			scanf ("%d %d", &a, &b);
			LCA(a,b);
			//printf ("LCA = %d\n", LCA(a,b));
			printf("%lld\n", ans);
		}
		
	}

	return 0;
}

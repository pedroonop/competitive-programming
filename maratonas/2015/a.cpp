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
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)
#define iii pair<int, ii>

int n, m;
vector<vii> g;

int main(){

	scanf("%d %d", &n, &m);
	g.resize(n + 1);

	go (i, m){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].pb(ii(v, w));
		g[v].pb(ii(u, w));
	}

	vi par, impar;
	par.resize(n + 1, INF);
	impar.resize(n + 1, INF);

	par[1] = impar[1] = 0;

	priority_queue<iii, vector<iii>, greater<iii> > pq;
	pq.push(iii(0, ii(1, 0)));

	while (!pq.empty()){
		iii topo = pq.top();
		pq.pop();
		int dist = topo.ff, u = topo.ss.ff, paridade = topo.ss.ss;
		if (paridade && dist > impar[u]) continue;
		if (!paridade && dist > par[u]) continue;
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i].ff, w = g[u][i].ss;
			if (paridade){
				if (par[v] > impar[u] + w){
					par[v] = impar[u] + w;
					pq.push(iii(par[v], ii(v, 0)));
				}
			}
			else{
				if (impar[v] > par[u] + w){
					impar[v] = par[u] + w;
					pq.push(iii(impar[v], ii(v, 1)));
				}
			}
		}
	}

	if (par[n] != INF) printf("%d\n", par[n]);
	else printf("-1\n");

	return 0;
}
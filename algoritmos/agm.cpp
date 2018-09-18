#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define go1(i, n) for (int i = 1; i <= (int)(n); i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()

vector<vi> g;
vector<vi> agm;

//Grafo de 1 ate N
//Adiciona vertice 0 como pai da raiz
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
		agm[u].pb(ii(pi[u], topo.ff));
		agm[pi[u]].pb(ii(u, topo.ff));
		go (i, g[u].size()){
			int v = g[u][i].ff, w = g[u][i].ss;
			if (pi[v] == -1){
				pq.push(make_pair(w, ii(v, u)));
			}
		}
	}
}

int main(){

	return 0;
}
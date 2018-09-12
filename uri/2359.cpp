#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 10010
#define go(i,n) for (int i = 1; i <= (int) n; i++)
#define goK(i,n,k) for (int i = 1; i <= (int) n-k; i++)
#define lld long long int
#define vi vector<int>
#define vii vector<ii>
using namespace std;

vector <vii> g;
vi cidades;

int main (){
	int n,m,q;
	while (scanf ("%d %d %d", &n, &m, &q) == 3){
		g.clear();
		cidades.clear();
		g.resize(n+1);
		go(i,m){
			int a, b, w;
			scanf ("%d %d %d", &a, &b, &w);
			g[a].push_back(ii(b,w));
			g[b].push_back(ii(a,w));
		}
		go(i,q){
			int a;
			scanf ("%d", &a);
			cidades.push_back(a);
		}
		priority_queue <ii, vector<ii>, greater<ii> > pq;
		vi dist;
		dist.assign(n+1, INF);
		dist[1] = 0;
		pq.push(ii(0,1));
		while (!pq.empty()){
			//printf ("v = %d\n", pq.top().ss);
			ii topo = pq.top();
			pq.pop();
			int w = topo.ff;
			int u = topo.ss;
			if (w > dist[u]) continue;
			
			for (auto v : g[u]){
				
				if (dist[v.ff] > dist[u] + v.ss){
					//printf ("%d %d\n", dist[u], w);
					dist[v.ff] = dist[u] + v.ss;
					pq.push(ii(dist[v.ff], v.ff));
				}
			}
		}
		
		int ans = INF;
		for (int u : cidades){
			//if (dist[u] == INF)
				ans = min (ans, dist[u]);
		}
		printf("%d\n", ans);
		
	}
	
	
	return 0;
}	

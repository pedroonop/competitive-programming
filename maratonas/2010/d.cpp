#include <bits/stdc++.h>
#define ii pair <int, int>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
using namespace std;


vector <vii> g;
priority_queue <ii, vector<ii>, greater<ii> >pq;

int main (){
	int n, m, c, k, x, y, z;
	while (scanf ("%d %d %d %d", &n, &m, &c, &k) == 4){
		if (n == 0 && m == 0 && c == 0 && k == 0) break;
		g.clear();
		pq = priority_queue <ii, vector<ii>, greater<ii> > ();
		g.resize(n+1);
		go(i,m){
			scanf ("%d %d %d", &x, &y, &z);
			g[x].push_back(ii(y,z));
			g[y].push_back(ii(x,z));
		}

		vi dist;
		dist.assign(n+1, INF);
		dist[k] = 0;
		pq.push(ii(0,k));
		while (!pq.empty()){
			ii topo = pq.top();
			pq.pop();
			int u = topo.ss;
			int peso = topo.ff;
			if (peso > dist[u]) continue;

			for (ii x : g[u]){
				int v = x.ff;
				int w = x.ss;

				if (u < c && fabs(u-v) > 1) continue;
				if (dist[u] + w < dist[v]){
					dist[v] = dist[u]+w;
					pq.push(ii(dist[v], v));
				}
			}
		}
		printf("%d\n", dist[c-1]);
	}
	return 0;
}
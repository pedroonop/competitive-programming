#include <bits/stdc++.h>

#define INF 1000000000

#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> g;


int main(){
	int V, E, k, u, v, w;

	scanf("%d %d", &V, &E);

	while(!(V == 0 && E == 0)){
		g.assign(V + 1, vii());

		for(int i = 0; i < E; i++){
			scanf("%d %d %d" ,&u ,&v ,&w);
			bool flag = false;

			for(int j = 0; j < (int) g[v].size(); j++){
				if(g[v][j].first == u){
					g[v][j].second = 0;
					g[u].pb(ii(v, 0));
					flag = true;
				}
			}

			if(!flag){
				g[u].pb(ii(v, w));
			}
		}

		vector<vi> dists(V + 1, vi());

		for(int i = 1; i <= V; i++){
			vi dist(V + 1, INF);
			dist[i] = 0;	

			priority_queue<ii, vector<ii>, greater<ii> > pq;
			pq.push(ii(0, i));

			while(!pq.empty()){
				ii front = pq.top();
				pq.pop();

				int d = front.first, u = front.second;

				if(d > dist[u]) continue;

				for(int i = 0; i < (int) g[u].size(); i++){
					ii v = g[u][i];

					if(dist[u] + v.second < dist[v.first]){
						dist[v.first] = dist[u] + v.second;
						pq.push(ii(dist[v.first], v.first));
					}	
				} 

			}

			dists[i] = dist;
		}

		scanf("%d" ,&k);

		for(int i = 0; i < k; i++){
			scanf("%d %d" ,&u ,&v);

			dists[u][v] != INF ? printf("%d\n", dists[u][v]) : printf("Nao e possivel entregar a carta\n");

		}
		printf("\n");
		scanf("%d %d" ,&V ,&E);
	}

	


	return 0;
}
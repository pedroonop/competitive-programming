/*
* @Author: Pedro Torres
* @Date:   2018-08-22 12:54:14
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-08-22 13:05:49
*/

#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> g;
vi taken;
priority_queue<ii, vector<ii>, greater<ii> > pq;


void process(int vtx){
	taken[vtx] = 1;
	for (int j = 0; j < (int)g[vtx].size(); j++) {
		ii v = g[vtx][j];
		if (!taken[v.first]) pq.push(ii(v.second, v.first)); 
	}   
}

int main() {
	int V, E, u, v, w, total;

	scanf("%d %d", &V, &E);

	while(!(V == 0 && E == 0)){
	  	g.assign(V, vii());
	  	taken.clear();
	  	pq = priority_queue<ii, vector<ii>, greater<ii> >();
	  	total = 0;

		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &u, &v, &w);
			g[u].pb(ii(v, w));
			g[v].pb(ii(u, w));
			total += w;
		}

		taken.assign(V, 0);
		process(0);
		int mst_cost = 0;

		while (!pq.empty()){
			ii front = pq.top(); pq.pop();
			u = front.second, w = front.first;
			if(!taken[u]){                
				mst_cost += w, process(u);
			}
		}
	  
		printf("%d\n", total - mst_cost);
		scanf("%d %d", &V, &E);
	}

  	return 0;
}
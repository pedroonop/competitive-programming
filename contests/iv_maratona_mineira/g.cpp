#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define llu unsigned long long int
#define ii pair<llu, llu>
#define iii pair<llu, ii>
#define atomo(p) p.first
#define sobra(p) p.second.first
#define mult(p) p.second.second

vector<vector<ii> > g;
/*
llu search(llu origem, llu destino, llu k){
	queue<iii> q;
	q.push(iii(origem, ii(k, 1)));
	llu cont = 0;
	while (!q.empty()){
		iii topo = q.front();
		q.pop();
		llu u = atomo(topo), s = sobra(topo), m = mult(topo);
		if (M[u][destino][s]) cont += M[u][destino][s];
		if (u == destino){
			cont += m;
		}
		if (s == 0) continue;
		for (int i = 0; i < g[u].size(); i++){
			llu v = g[u][i].first, w = g[u][i].second;
			q.push(iii(v, ii(s - 1, m * w)));
		}
	}
	return cont;
}*/

llu M[100][100][100];

llu search(llu origem, llu destino, llu k, llu multiplicador){
	if (M[origem][destino][k]) return M[origem][destino][k];
	llu cont = 0;
	if (origem == destino){
		cont += multiplicador;
	}
	if (k == 0) return cont;
	for (int i = 0; i < g[origem].size(); i++){
		llu v = g[origem][i].first, w = g[origem][i].second;
		cont += search(v, destino, k - 1, multiplicador * w);
	}
	M[origem][destino][k] = cont;
	return cont;
}

int main(){

	llu n, m, x;

	//scanf("%llu %llu %llu", &n, &m, &x);
	cin >> n >> m >> x;
	g.resize(n + 1);

	for (int i = 0; i < m; i++){
		llu u, v, w;
		//scanf("%llu %llu %llu", &u, &v, &w);
		cin >> u >> v >> w;
		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}

	llu t;
	//scanf("%llu", &t);
	cin >> t;

	while (t--){
		llu u, v;
		//scanf("%llu %llu", &u, &v);
		cin >> u >> v;
		//printf("%llu\n", search(u, v, x, 1));
		cout << search (u,v,x,1) << endl;
	}

	return 0;
}
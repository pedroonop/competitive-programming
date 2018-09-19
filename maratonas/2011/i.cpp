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
#define iii pair<int, ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define linha pair<dd, dd>
#define id pair<int, double>
#define dii pair<double, ii>
#define EPS 1e-7

dd operator+(dd a, dd b){
	return dd(a.x + b.x, a.y + b.y);
}

dd operator-(const dd &a, const dd &b){
	return dd(a.x - b.x, a.y - b.y);
}

double module(dd a){
	return sqrt(a.x * a.x + a.y * a.y);
}

double dist(dd a, dd b){
	return module(b - a);
}

double cross(dd a, dd b){
	return a.x * b.y - a.y * b.x;
}

int t, m, c;
linha muros[51];
dd portais[51];

bool cruza(dd a, dd b, dd c, dd d){
	dd ab = b - a;
	dd cd = d - c;
	dd cb = b - c;
	dd db = b - d;
	dd ad = d - a;
	dd bd = d - b;
	if (max(a.x, b.x) < min(c.x, d.x) || 
		max(a.y, b.y) < min(c.y, d.y) || 
		max(c.x, d.x) < min(a.x, b.x) || 
		max(c.y, d.y) < min(a.y, b.y))
		return false;
	return cross(ab, cb) * cross(ab, db) < EPS && cross(cd, ad) * cross(cd, bd) < EPS;
}

bool livre(dd a, dd b){
	dd c = b - a;
	go (i, m){
		if (module(a - muros[i].ff) < EPS ||
			module(b - muros[i].ff) < EPS ||
			module(a - muros[i].ss) < EPS ||
			module(b - muros[i].ss) < EPS) continue;
		if (cruza(a, b, muros[i].ff, muros[i].ss)) return false;
	}
	return true;
}

vector<vector<id> > g;

int main(){

	while (scanf("%d %d %d", &t, &m, &c) == 3){
		go (i, m){
			scanf("%lf %lf %lf %lf", &muros[i].ff.x, &muros[i].ff.y, &muros[i].ss.x, &muros[i].ss.y);
		}

		go (i, c){
			scanf("%lf %lf", &portais[i].x, &portais[i].y);
		}

		dd inicial, final;
		scanf("%lf %lf %lf %lf", &inicial.x, &inicial.y, &final.x, &final.y);

		vector<dd> pontos;
		pontos.pb(inicial);
		pontos.pb(final);

		go (i, c){
			pontos.pb(portais[i]);
		}
		go (i, m){
			pontos.pb(muros[i].ff);
			pontos.pb(muros[i].ss);
		}

		g.clear();
		g.resize(pontos.size() + 1);

		for (int i = 0; i < pontos.size(); i++){
			for (int j = i + 1; j < pontos.size(); j++){
				if (livre(pontos[i], pontos[j])){
					g[i].pb(id(j, dist(pontos[i], pontos[j])));
					g[j].pb(id(i, dist(pontos[i], pontos[j])));
				}
			}
		}
	/*
		for (int i = 0; i < pontos.size(); i++){
			printf("%d: %.0lf %.0lf: ", i, pontos[i].x, pontos[i].y);
			for (int j = 0; j < g[i].size(); j++){
				printf("(%d, %.2lf) ", g[i][j].ff, g[i][j].ss);
			}
			printf("\n");
		}
	*/

		vector<vector<double> > dist_;
		dist_.clear();
		dist_.resize(t + 1);

		go (i, t + 1){
			dist_[i].assign(pontos.size(), INF);
		}

		dist_[t][0] = 0;

		priority_queue<dii, vector<dii>, greater<dii> > pq;
		pq.push(dii(0, ii(0, t)));

		while (!pq.empty()){
			dii topo = pq.top();
			pq.pop();
			double d = topo.ff;
			int t_ = topo.ss.ss, u = topo.ss.ff;
			if (dist_[t_][u] < d) continue;
			for (int i = 0; i < g[u].size(); i++){
				int v = g[u][i].ff;
				double w = g[u][i].ss;
				if (t_ > 0 && 2 <= u && u <= c + 1 && 2 <= v && v <= c + 1){
					if (dist_[t_ - 1][v] > d){
						dist_[t_ - 1][v] = d;
						pq.push(dii(d, ii(v, t_ - 1)));
					}
				}
				if (dist_[t_][v] > d + w){
					dist_[t_][v] = d + w;
					pq.push(dii(dist_[t_][v], ii(v, t_)));
				}
			}
		}

		double minimo = INF;

		go (i, t + 1){
			minimo = min(minimo, dist_[i][1]);
		}

		printf("%.1lf\n", minimo);
	}


	return 0;
}
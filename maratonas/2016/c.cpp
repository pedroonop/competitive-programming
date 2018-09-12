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
#define disp pair<pair<ii, ii>, pair<ii, ii> >
#define p1 ff.ff.ff
#define p2 ff.ff.ss
#define p3 ff.ss.ff
#define p4 ff.ss.ss
#define p5 ss.ff.ff
#define p6 ss.ff.ss
#define p7 ss.ss.ff
#define p8 ss.ss.ss
#define id pair<int, disp>

id troca(disp aux, int i){
	int custo;
	if (i == 0){
		swap(aux.p1, aux.p2);
		custo = aux.p1 + aux.p2;
	}
	if (i == 1){
		swap(aux.p1, aux.p5);
		custo = aux.p1 + aux.p5;
	}
	if (i == 2){
		swap(aux.p2, aux.p3);
		custo = aux.p2 + aux.p3;
	}
	if (i == 3){
		swap(aux.p2, aux.p6);
		custo = aux.p2 + aux.p6;
	}
	if (i == 4){
		swap(aux.p3, aux.p4);
		custo = aux.p3 + aux.p4;
	}
	if (i == 5){
		swap(aux.p3, aux.p7);
		custo = aux.p3 + aux.p7;
	}
	if (i == 6){
		swap(aux.p4, aux.p8);
		custo = aux.p4 + aux.p8;
	}
	if (i == 7){
		swap(aux.p5, aux.p6);
		custo = aux.p5 + aux.p6;
	}
	if (i == 8){
		swap(aux.p6, aux.p7);
		custo = aux.p6 + aux.p7;
	}
	if (i == 9){
		swap(aux.p7, aux.p8);
		custo = aux.p7 + aux.p8;
	}
	return id(custo, aux);
}

int main(){

	disp o, d;

	scanf("%d %d %d %d %d %d %d %d", &o.p1, &o.p2, &o.p3, &o.p4, &o.p5, &o.p6, &o.p7, &o.p8);
	scanf("%d %d %d %d %d %d %d %d", &d.p1, &d.p2, &d.p3, &d.p4, &d.p5, &d.p6, &d.p7, &d.p8);

	map<disp, int> dist;

	priority_queue<id, vector<id>, greater<id> > pq;

	pq.push(id(0, o));
	dist[o] = 0;

	while (!pq.empty()){
		id topo = pq.top();
		pq.pop();
		int d = topo.ff;
		disp u = topo.ss;
		if (dist.find(u) == dist.end()){
			dist[u] = INF;
		}
		if (dist[u] < d) continue;
		for (int i = 0; i < 10; i++){
			id aux = troca(u, i);
			int w = aux.ff;
			disp v = aux.ss;
			if (dist.find(v) == dist.end()){
				dist[v] = INF;
			}
			if (dist[v] > d + w){
				dist[v] = d + w;
				pq.push(id(d + w, v));
			}
		}
	}

	printf("%d\n", dist[d]);

	return 0;
}
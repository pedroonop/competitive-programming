#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)(n); i++)
#define go1(i, n) for (int i = 1; i <= (int)(n); i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)

vector<vi> g;
int cor[200001];

int main(){

	int t = 0;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		g.clear();
		g.resize(n + 1);

		int u, v;
		go (i, m){
			scanf("%d %d", &u, &v);
			g[u].pb(v);
			g[v].pb(u);
		}

		vi sA, sB;

		go1 (i, n) cor[i] = 0;

		queue<int> q;
		q.push(1);
		cor[1] = 1;

		while (!q.empty()){
			int u = q.front();
			q.pop();
			if (cor[u] == 1) sA.pb(u);
			else sB.pb(u);
			for (int v : g[u]){
				if (cor[v] == 0){
					if (cor[u] == 1) cor[v] = 2;
					else cor[v] = 1;
					q.push(v);
				}
			}
		}

		if (sA.size() < sB.size()){
			printf("%lu\n", sA.size());
			for (int u : sA) printf("%d ", u);
			printf("\n");
		}
		else{
			printf("%lu\n", sB.size());
			for (int u : sB) printf("%d ", u);
			printf("\n");
		}
	}

	return 0;
}
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
#define MAXN 5001

vector<int> g[MAXN];
int cor[MAXN];
int idade[MAXN];
bool fst_flag = true;

int dfs(int u, int id){
	cor[u] = 1;
	int min_;
	fst_flag ? min_ = INF : min_ = idade[u];
	fst_flag = false;
	for (int i = 0; i < g[u].size(); i++){
		if (!cor[g[u][i]]){
			min_ = min(min_, dfs(g[u][i], id));
		}
	}
	return min_;
}

void troca(int u, int v, int n){
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < (int) g[i].size(); j++){
			if (g[i][j] == u){
				g[i][j] = v;

			}
			else if(g[i][j] == v){
				g[i][j] = u;
			}
		}
	}

	// swap(idade[u], idade[v]);
	swap(g[u], g[v]);
}

int main(){
	int n, m, l;
	int u, v, id;
	char op;

	while (scanf("%d %d %d" ,&n ,&m ,&l) != EOF){
		fst_flag = true;
		memset(cor, 0, sizeof(cor));
		memset(idade, 0, sizeof(idade));
		for (int i = 0; i <= MAXN; i++) g[i].clear();
		for (int i = 1; i <= n; i++){
			scanf("%d" ,&idade[i]);
		}

		for (int i = 0; i < m; i++){
			scanf("%d %d" ,&u ,&v);

			g[v].pb(u);
		}

		for (int i = 0; i < l; i++){
			scanf(" %c" ,&op);
			if (op == 'P'){
				memset(cor, 0, sizeof(cor));
				fst_flag = true;
				scanf("%d" ,&u);
				int r = dfs(u, idade[u]);
				r == INF ? printf("*\n") : printf("%d\n", r);
			}
			if (op == 'T'){
				scanf("%d %d" ,&u ,&v);
				troca(u, v, n);
			}
		}
		
	}


	return 0;
}
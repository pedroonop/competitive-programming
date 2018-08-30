#include <bits/stdc++.h>

#define pb push_back
#define MAXN 2005

using namespace std;

typedef pair<int, int> ii;

list<int> g[MAXN];
list<int> gt[MAXN];
int cor[MAXN];
int cort[MAXN];


void dfs(int s){
	cor[s] = 1;
	list<int>::iterator it;
	for(it = g[s].begin(); it != g[s].end(); it++){
		if(!cor[*it]){
			dfs(*it);
		}
	}
}

void dfst(int s){
	cort[s] = 1;
	list<int>::iterator it;
	for(it = gt[s].begin(); it != gt[s].end(); it++){
		if(!cort[*it]){
			dfst(*it);
		}
	}
}

int main(){
	int n, m;
	int u, v, p;

	scanf("%d %d" ,&n ,&m);

	while(!(n == 0 && m == 0)){
		for (int i = 0; i < MAXN; i++){
			g[i].clear();
			gt[i].clear();	
		} 
		memset(cor, 0, sizeof(cor));
		memset(cort, 0, sizeof(cort));

		for (int i = 0; i < m; i++){
			scanf("%d %d %d" ,&u ,&v ,&p);

			if (p == 1){
				g[u].pb(v);
				gt[v].pb(u);
			}
			if (p == 2){
				g[u].pb(v);
				g[v].pb(u);

				gt[u].pb(v);
				gt[v].pb(u);
			}
		}

		bool flag = true;

		dfs(1);
		dfst(1);

		for(int i = 1; i <= n; i++){
			if(!cor[i] || !cort[i]){
				flag = false;
			}
		}

		flag ? printf("1\n") : printf("0\n");

		scanf("%d %d" ,&n ,&m);
	}


	return 0;
}
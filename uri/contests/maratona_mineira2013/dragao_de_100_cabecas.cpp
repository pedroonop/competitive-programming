#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 11
#define go(i,n) for (int i = 0; i < (int) n; i++)
#define goK(i,n,k) for (int i = 1; i <= (int) n-k; i++)
using namespace std;

int cortes[MAXN];
int cabecas[MAXN];
map <int, int> seen;

queue <ii> q;

int main (){
	int n;
	while (scanf ("%d", &n) == 1){
		if (n == 0) break;
		q = queue <ii> ();
		seen.clear();
		go(i,n){
			scanf ("%d", &cortes[i]);
		}
		go(i,n){
			scanf ("%d", &cabecas[i]);
		}
		
		q.push(ii(100, 0));
		bool flag = false;
		
		
		while (!q.empty()){
			if (flag) break;
			ii topo = q.front();
			q.pop();
			int qtd = topo.ff;
			int jog = topo.ss;
			if (qtd > 1000) continue;
			//printf ("%d %d\n", qtd, jog);
			
			
			if (seen[qtd]) continue;
			seen[qtd] = 1;
			
			go(i,n){
				if (qtd < cortes[i]) continue;
				if (qtd-cortes[i] == 0){
					printf ("%d\n", jog+1);
					flag = true;
					break;
				}
				q.push(ii(qtd-cortes[i]+cabecas[i], jog+1));
			}
			
		}
		
		if (!flag)
			printf ("cavaleiro morreu\n");
	
	}	
	return 0;
}

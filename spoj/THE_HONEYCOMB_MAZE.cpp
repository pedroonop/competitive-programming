#include <bits/stdc++.h>
#define go(i,n) for (int i = 0; i <(int) n; i++)
#define ii pair <int, int>
using namespace std;
char matriz[101][101];
int posI, posJ, K;

int movI[] = {1, -1, 0, 0};
int movJ[] = {0, 0, 1, -1}; 
int n, m;
bool valido (int i, int j){
	if (i < 0 || j < 0 || i >= n || j >= m) return false;
	return true;
}


map <ii, int> seen;
bool flag = false;
bool dfs (int i, int j, map<ii, int> seen, int k){
	//printf ("i = %d  j  = %d k = %d\n", i, j, k);
	if (k == K) return false;
	if (flag) return flag;
	if (i == posI && j == posJ && seen[ii(i,j)] && k > 3
	) return flag = true;
	if (matriz[i][j] == '*') return false;
	ii x = ii(i,j);
	if (seen[x]) return false;
	seen[x] = 1;
	bool aux = false;
	for (int x = 0; x < 4; x++){
		if (valido(i+movI[x], j+movJ[x]))
			aux = aux || dfs (i+movI[x], j+movJ[x], seen, k+1);
	}
	return aux;
}

int main (){
	scanf ("%d %d", &n, &m);
	scanf ("%d", &K);
	scanf ("%d %d", &posI, &posJ);
	posI--;
	posJ--;
	go (i, n){
		go (j, m){
			scanf ("  %c", &matriz[i][j]);
		}
	}
	if (dfs (posI, posJ, seen, 1)) printf ("YES\n");
	else printf ("NO\n");
	return 0;
}

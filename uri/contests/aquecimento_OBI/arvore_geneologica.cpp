#include <bits/stdc++.h>
#define MAXN 310
#define vi vector <int>
#define ff first
#define ss second
using namespace std;
map <string, int> ma;
int indice_disponivel = 1;
vi g[MAXN];
int seen[MAXN];

void dfs(int v){
	if (seen[v]) return;
	seen[v] = 1;
	for (int u : g[v]){
		dfs (u);
	}
}


int main (){
	string a,b,c;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		//cout << a << endl;
		if (ma.find(a) == ma.end()){
			//cout << "entrou com " << a << endl;
			ma[a] = indice_disponivel++;
			//printf ("indice = %d\n", ma[a]);
		}
		if (ma.find(c) == ma.end()){
			ma[c] = indice_disponivel++;
			//cout << "entrou com " << c << endl;
		}
		g[ma[c]].push_back(ma[a]);
		g[ma[a]].push_back(ma[c]);
	}
	
	int cont = 0;
	for (int i = 1; i <= n; i++){
		if (!seen[i]) {cont++; dfs(i);}
		
	}
	printf ("%d\n", cont);
	return 0;
}

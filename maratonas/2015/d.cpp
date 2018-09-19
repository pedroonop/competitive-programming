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

int l, c;
string matriz[101][101];
map<string, int> mapa;
set<string> info_linha[101];
set<string> info_coluna[101];
set<string> vars;

void set_var(string var, int valor){
	mapa[var] = valor;
	go (i, l) info_linha[i].delete(var);
	go (j, c) info_coluna[j].delete(var);
}

int main(){
	fastcin;


	cin >> l >> c;

	int v_linha[101];
	int v_coluna[101];

	go (i, l){
		go (j, c){
			cin >> matriz[i][j];
			vars.insert(matriz[i][j]);
			info_linha[i].insert(matriz[i][j]);
			info_coluna[j].insert(matriz[i][j]);
		}
		cin >> v_linha[i];
	}
	go (j, c){
		cin >> v_coluna[j];
	}

	while (!vars.empty()){
		go (i, l){
			if (info_linha[i].size() == 1){
				
			}
		}
	}

	return 0;
}
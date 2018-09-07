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

vector<int> inicial;
vector<int> final;

int valido (int n){
	if (n < 0) return 0;
	return n;
}



vector<int> gera_tras (int dobra, vector<int> v){
	int inicio = dobra;
	int fim = dobra + 1;
	int n = v.size();
	vector <int> novo;
	while (inicio >= 0 || fim < n){
		int valor = 0;
		if (inicio >= 0) valor += v[inicio];
		if (fim < n) valor += v[fim];
		novo.push_back(valor);
		//printf ("valor = %d inicio = %d  fim = %d\n", valor, inicio, fim);
		fim++;
		inicio--;
	}
	return novo;
}

vector <int> gera_frente (int dobra, vector<int> v){
	vi novo = gera_tras(dobra, v);
	reverse(novo.begin(), novo.end());
	return novo;
}


void p (std::vector<int> v){
	go(i,v.size()){
		printf("%d ", v[i]);
	}
	printf("\n");
}

map <vi, int> seen;


bool dfs (vi u){
	if (u.size() < final.size()) return false;
	if (seen[u] == 100) return true;
	if (seen[u]) return false;
	seen[u] = 1;

	bool ans = false;
	for (int i = 0; i < u.size(); i++){
		ans = ans || dfs(gera_tras(i,u));
		ans = ans || dfs(gera_frente(i,u));
	}
	return ans;
}



int main(){
	int n, m;
	while (scanf ("%d", &n) == 1){
		inicial.assign(n,0);
		go(i,n){
			scanf ("%d", &inicial[i]);
		}
		scanf ("%d", &m);
		final.assign(m,0);
		go(i,m){
			scanf ("%d", &final[i]);
		}
		seen[final] = 100;
		
		if (dfs(inicial)){
			printf("S\n");
		}
		else{
			printf("N\n");
		}
		
	}

	return 0;
}
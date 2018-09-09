#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)(n); i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))

dd operator-(dd a, dd b){
	return dd(a.x - b.x, a.y - b.y);
}

double dist(dd a, dd b){
	dd c = a - b;
	return sqrt(c.x * c.x + c.y * c.y);
}

map<vector<dd>, double> M;

int add(int a, int b, int n){
	int c = a + b;
	if (c > n) c -= n;
	return c;
}

double solve(vector<dd> pontos){
	map<vector<dd>, double>::iterator it = M.find(pontos);
	if (it != M.end()) return it->second;
	int n = pontos.size();
	if (n == 4) return 0;
	double minimo = INF;
	for (int i = 0; i < 4; i++){
		vector<dd> aux;
		for (int j = 0; j < n; j++){
			if (j == i + 1 || j == i + 2) continue;
			aux.pb(pontos[j]);
		}
		double cost = dist(pontos[i], pontos[add(i, 3, n)]);
		minimo = min(minimo, cost + solve(aux));
	}
	M[pontos] = minimo;
	return minimo;
}

vector<dd> pontos;
int main(){

	int n;

	scanf("%d\n", &n);

	pontos.resize(2 * n);

	go (i, 2 * n){
		scanf("%lf %lf", &pontos[i].ff, &pontos[i].ss);
	}

	printf("%.4lf\n", solve(pontos));

	return 0;
}
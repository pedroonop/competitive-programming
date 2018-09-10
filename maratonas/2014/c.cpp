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

class plano{
public:
	int a, b, c, d;
	bool lado(int x, int y, int z){
		return a * x + b * y + c * z > d;
	}
};

map<vector<bool>, int> mapa;

int main(){

	int m, n;
	scanf("%d %d", &m, &n);

	plano p[501];
	go (i, m){
		scanf("%d %d %d %d", &p[i].a, &p[i].b, &p[i].c, &p[i].d);
	}

	int maximo = 0;

	int x, y, z;
	go (i, n){
		scanf("%d %d %d", &x, &y, &z);
		vector<bool> regiao;
		regiao.resize(m);
		go (j, m){
			regiao[j] = p[j].lado(x, y, z);
		}
		mapa[regiao]++;
		maximo = max(maximo, mapa[regiao]);
	}

	printf("%d\n", maximo);
	return 0;
}
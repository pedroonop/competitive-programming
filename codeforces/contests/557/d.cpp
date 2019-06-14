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

int n, m;

ii operator+(ii a, int b){
	int f = a.ff + b, s = a.ss + b;
	if (f > n) f -= n;
	if (s > n) s -= n;
	return ii(f, s);
}

int operator-(ii a, ii b){
	int r = abs(a.ff - b.ff);
	int aux = a.ss + r;
	if (aux > n) aux -= n;
	printf("%d %d\n", aux, b.ss);
	if (aux != b.ss) return -1;
	return r;
}

int main(){

	scanf("%d %d", &n, &m);

	ii vet[200001];

	go (i, m){
		scanf("%d %d", &vet[i].ff, &vet[i].ss);
	}

	sort(vet, vet + m);

	vector<int> divisores;
	divisores.pb(1);

	for (int i = 2; i * i <= m; i++){
		if (m % i == 0){
			divisores.pb(i);
			divisores.pb(m / i);
		}
	}


	for (int x : divisores){
		int k = vet[x] - vet[0];
		if (k == -1) continue;
		int qtd = m / x;
		bool flag = true;
		for (int i = 0; i < qtd - 1; i++){
			if (!flag) break;
			for (int j = 0; j < x; j++){
				if (vet[x * i + j] + k != vet[x * (i + 1) + j]){
					printf("%d %d %d\n", x, x * i + j, x * (i + 1) + j);
					flag = false;
					break;
				}
			}
		}
		if (flag){
			for (int j = 0; j < x; j++){
				if (vet[x * (qtd - 1) + j] != vet[j]){
					printf("%d %d %d\n", x, x * (qtd - 1) + j, j);
					flag = false;
					break;					
				}
			}
		}
		if (flag){
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");
	return 0;
}
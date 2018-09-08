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
#define MAXN 1000000
#define m 1000000007

bool comp(int a, int b){
	return a > b;
}

int main(){

	int n, k;

	while (scanf("%d %d", &n, &k) == 2){
		int vet[MAXN + 1];

		go (i, n){
			scanf("%d", vet + i);
		}

		sort(vet, vet + n, comp);

		int cont = 0;

		go (i, k){
			cont = (cont + vet[i]) % m;
		}

		printf("%d\n", cont);		
	}


	return 0;
}
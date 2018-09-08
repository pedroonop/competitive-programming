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

int main(){

	int n;
	while (scanf("%d", &n) == 1){
		n *= 10;

		int vet[MAXN + 1], inv[MAXN + 1];
		int cont = 0;
		go (i, n){
			scanf("%d", vet + i);
			cont += vet[i];
			inv[i] = -vet[i];
		}

		int maior_total = 0;
		int maior_atual = 0;

		int maior_total_ = 0;
		int maior_atual_ = 0;

		go(i, n){
			maior_atual += vet[i];
			if (maior_atual < 0) maior_atual = 0;
			if (maior_total < maior_atual) maior_total = maior_atual;

			maior_atual_ += inv[i];
			if (maior_atual_ < 0) maior_atual_ = 0;
			if (maior_total_ < maior_atual_) maior_total_ = maior_atual_;		
		}

	//	printf("%d %d\n", maior_total, maior_total_);

		printf("%d\n", max(maior_total, maior_total_ + cont));		
	}

	return 0;
}
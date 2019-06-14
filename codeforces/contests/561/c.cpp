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

int main(){

	int n;
	scanf("%d", &n);

	int vet[200020];
	for (int i = 0; i < n; i++){
		scanf("%d", &vet[i]);
		vet[i] = abs(vet[i]);
	}

	sort(vet, vet + n);

	llu cont = 0;
	for (int i = 0; i < n; i++){
		int j = upper_bound(vet + i + 1, vet + n, vet[i]<<1) - vet;
		cont += (j - i) - 1;
	}

	printf("%llu\n", cont);

	return 0;
}
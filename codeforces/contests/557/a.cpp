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

	int n, h, m;

	scanf("%d %d %d", &n, &h, &m);

	int vet[51];
	go (i, n){
		vet[i] = h;
	}

	go (i, m){
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		l--;
		r--;
		for (int j = l; j <= r; j++){
			vet[j] = min(vet[j], x);
		}
	}

	int cont = 0;
	go (i, n){
		cont += vet[i] * vet[i];
	}

	printf("%d\n", cont);

	return 0;
}
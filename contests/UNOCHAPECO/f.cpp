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
#define MAXN 15485863
#define M 10000031

bool isComposite[MAXN + 1];

lld add(lld a, lld b){
	lld c = a + b;
	if (c > M) c -= M;
	return c;
}

int main(){


	ms(isComposite, false);

	isComposite[1] = true;

	vector<lld> acumulado;
	acumulado.pb(0);

	int aux;
	for (int i = 2; i <= MAXN; i++){
		if (isComposite[i]) continue;
		aux = i;
		if (aux > M) aux -= M;
		acumulado.pb(add(acumulado.back(), aux));
		for (int j = i + i; j <= MAXN; j += i){
			isComposite[j] = true;
		}
	}

	int a, b;
	while (scanf("%d %d", &a, &b) == 2){
		lld result = acumulado[b] - acumulado[a - 1];
		if (result < 0) result += M;
		printf("%lld\n", result);
	}

	return 0;
}
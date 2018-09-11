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

lld f(lld n, lld q){
	return 4 * q * (n - q);
}

lld search(lld n, lld v){
	lld inicio = 0, fim = n/2;
	lld ans = 0;
	while (inicio < fim){
		lld meio = (inicio + fim) / 2;
		if (f(n, meio) <= v) inicio = meio + 1;
		else fim = meio;
	}
	return inicio - 1;
}

int main(){

	lld n = 8, v = 27;

	scanf("%lld %lld", &n, &v);
	lld q = search(n, v);

	lld x = q, y = q - 1;
	lld n_ = n - f(n, q);

	if (n_ > n - 2 * q){
		n_ -= n - 2 * q;
		y += n - 2 * q;
	}
	else{
		printf("%lld %lld\n", x, y + n_);
		return 0;
	}
	if (n_ > n - 2 * q - 1){
		n_ -= n - 2 * q - 1;
		x += n - 2 * q - 1;
	}
	else{
		printf("%lld %lld\n", x + n_, y);
		return 0;
	}
	if (n_ > n - 2 * q - 1){
		n_ -= n - 2 * q - 1;
		y -= n - 2 * q - 1;
	}
	else{
		printf("%lld %lld\n", x, y - n_);
		return 0;		
	}
	x -= n_;
	printf("%lld %lld\n", x, y);

	return 0;
}
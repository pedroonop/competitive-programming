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
#define INF 0x3f3f3f3f3f3f3f3fLL
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){

	lld a, b, c, d;

	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	if (c % a != 0 || (a == b) || (c == d)){
		printf("-1\n");
		return 0;
	}

	lld menor = INF;

	for (lld n = 1; n * n <= c; n++){
		if (n % a == 0 && c % n == 0 && n % b != 0 && d % n != 0){
			menor = min(menor, n);
		}
		if (c % n == 0){
			lld n_ = c / n;
			if (n_ % a == 0 && n_ % b != 0 && d % n_ != 0){
				menor = min(menor, n_);
			}
		}
	}

	if (menor != INF){
		printf("%lld\n", menor);
	}
	else{
		printf("-1\n");
	}

	return 0;
}
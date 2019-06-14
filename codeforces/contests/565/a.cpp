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

	int q;
	scanf("%d", &q);

	while (q--){
		llu n;
		scanf("%llu", &n);

		llu cont = 0;

		while (n > 1){
			cont++;
			if (!(n&1)) n = n>>1;
			else if (n % 3 == 0) n = (n / 3)<<1;
			else if (n % 5 == 0) n = (n / 5)<<2;
			else break;
		}

		if (n == 1){
			printf("%llu\n", cont);
		}
		else{
			printf("-1\n");
		}		
	}


	return 0;
}
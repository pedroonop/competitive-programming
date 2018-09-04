#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<lld, lld>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (lld i = 0; i < (lld)n; i++)
#define vi vector <lld>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second

bool isComposite[1000001];

int main(){

	lld n;
	lld raiz = 100000;
	isComposite[1] = 1;
	vector<lld> primes;
	for (lld i = 2; i <= raiz; i++){
		if (isComposite[i]) continue;
		primes.pb(i);
		for (lld j = i + i; j <= raiz; j += i){
			isComposite[j] = true;
		}
	}

	while (scanf("%lld", &n) == 1){

		lld phi = n;

		for (lld i = 0; primes[i] * primes[i] <= n; i++){
			if (n % primes[i] == 0){
				while (n % primes[i] == 0) n = n / primes[i];
				phi -= phi / primes[i];
			}
		}

		if (n > 1) phi -= phi / n;

		printf("%lld\n", phi/2);
		
	}

	return 0;
}
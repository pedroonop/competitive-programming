#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned

bool isPrime[12000002];
int main(){

	llu n, m;
	scanf("%llu", &m);
	n = 12000000;

	isPrime[1] = 0;

	memset(isPrime, true, sizeof(isPrime));

	llu cont = 0;
	for (llu i = 2; i <= n; i++){
		if (!isPrime[i]) continue;
		cont++;
		if (cont == m){
			printf("%llu\n", i);
			break;
		}
		for (llu j = i + i; j <= n; j += i){
			isPrime[j] = 0;
		}
	}

	return 0;
}
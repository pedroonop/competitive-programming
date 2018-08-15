#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define N 1500000

int main(){

	bool isPrime[N + 1];
	memset(isPrime, true, sizeof(isPrime));

	isPrime[1] = 0;

	vector<llu> primo;

	for (llu i = 2; i <= N; i++){
		if (!isPrime[i]) continue;
		primo.push_back(i);
		for (llu j = i + i; j <= N; j += i){
			isPrime[j] = 0;
		}
	}

	llu q;
	scanf("%llu", &q);

	while (q--){
		llu n;
		scanf("%llu", &n);

		llu p = lower_bound(primo.begin(), primo.end(), n) - primo.begin();
		printf("%llu\n", p + 1);
	}

	return 0;
}
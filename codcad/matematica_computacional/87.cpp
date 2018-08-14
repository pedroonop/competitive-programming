#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	bitset<10000002> isPrime;
	isPrime.set();
	isPrime[1] = 0;

	for (int i = 2; i <= n; i++){
		if (!isPrime[i]) continue;
		for (int j = 2; i * j <= n; j++){
			isPrime[i * j] = 0;
		}
	}

	for (int i = 2; i <= n; i++){
		if (isPrime[i]){
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

llu L[1000002];

int main(){

	llu t, n;

//	scanf("%d %d", &t, &n);
	t = 1000000; n = 10;

	for (llu i = 3; i <= t / 4; i++){
		llu j;
		if (i % 2) j = 1;
		else j = 2;
		for (; j < i - 1; j += 2){
			if (i * i - (j * j) <= t)
				L[i * i - (j * j)]++;
		}
	}

	llu cont = 0;
	for (int i = 1; i <= t; i++){
		if (1 <= L[i] && L[i] <= n) cont++;
	}

	printf("%llu\n", cont);

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned

int main(){

	llu n;

	scanf("%llu", &n);

	int cont = 0;
	for (int i = 0; i <= 63; i++){
		if (n & (1L<<i)) cont++;
	}

	printf("%d\n", cont);

	return 0;
}
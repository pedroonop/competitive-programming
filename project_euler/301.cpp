#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned

int main(){
	llu maximo;
	scanf("%llu", &maximo);

	llu cont = 0;
	for (llu n = 1; n <= maximo; n++){
		if ((n ^ (2 * n) ^ (3 * n)) == 0) cont++;
	}

	printf("%llu\n", cont);
	return 0;
}
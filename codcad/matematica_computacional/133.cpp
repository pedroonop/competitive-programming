#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned

int main(){

	llu n;
	scanf("%llu", &n);
	n++;

	int cont = 0;
	for (int i = 0; i <= 64; i++){
		if (n & (1L<<i)) cont++;
	}

	if (cont == 1) printf("S\n");
	else printf("N\n");

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned

llu mdc(llu a, llu b){
	if (b == 0) return a;
	return mdc(b, a % b);
}

int main(){

	llu a, b;
	scanf("%llu %llu", &a, &b);

	printf("%llu\n", (a / mdc(a, b)) * b);

	return 0;
}
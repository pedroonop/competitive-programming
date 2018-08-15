#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned

llu mdc(llu a, llu b){
	if (b == 0) return a;
	return mdc(b, a % b);
}

int main(){

	llu a, b, c, d;

	scanf("%llu %llu %llu %llu", &a, &b, &c, &d);

	llu den = b * d;
	llu num = a * (den / b) + c * (den / d);

	llu maximo = mdc(den, num);

	num = num / maximo;
	den = den / maximo;

	printf("%llu %llu\n", num, den);

	return 0;
}
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

	for (llu i = b; i > 0; i--){
		if (mdc(a, i) == 1){
			printf("%llu\n", i);
			break;
		}
	}

	return 0;
}
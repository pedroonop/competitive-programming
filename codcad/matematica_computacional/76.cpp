#include <bits/stdc++.h>

using namespace std;

int main(){

	long long unsigned n;

	scanf("%llu", &n);

	long long unsigned sqrt_n = sqrt(n);

	bool has_div = false;

	if (n == 1){
		printf("N\n");
		return 0;
	}

	if (n == 2){
		printf("S\n");
		return 0;	
	}

	for (long long unsigned i = 2; i <= sqrt_n + 1; i++){
		if (n % i == 0){
			has_div = true;
			break;
		}
	}

	if (has_div){
		printf("N\n");
	}
	else{
		printf("S\n");
	}

	return 0;
}
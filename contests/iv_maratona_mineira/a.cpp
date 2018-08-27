#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int main(){

	int n;

	scanf("%d", &n);

	if (n == 1){
		printf("N\n");
		return 0;
	}

	int sqrt_n = sqrt(n);

	if (sqrt_n * sqrt_n == n && is_prime(sqrt_n)){
		printf("S\n");
	}
	else{
		printf("N\n");
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	long long int out = 0, aux;
	for (int i = 0; i < n; i++){
		scanf("%lld", &aux);
		out = out | aux;
	}

	printf("%lld\n", out);

	return 0;
}
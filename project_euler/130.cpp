#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

llu A(llu n){
	llu r = 1;
	llu cont = 1;
	while (r % n != 0){
		r = (10 * r + 1) % n;
		cont++;
		if (cont > n) break;
	}
	printf("%llu\n", r);
	return cont;
}

bool is_composite[1000001];
int main(){

	vector<int> composite;

	for (int i = 2; i <= 1000000; i++){
		if (is_composite[i]){
			composite.pb(i);
			continue;
		}
		for (int j = i + i; j <= 1000000; j += i){
			is_composite[j] = true;
		}
	}

	int cont = 0;
	llu soma = 0;
	llu i = 0;
	while (cont < 25){
		llu n = composite[i];
		if (n % 2 != 0 && n % 5 != 0){
			llu a = A(n);
			if ((n - 1) % a == 0){
//				printf("%llu %llu\n", n - 1, a);
				cont++;
				soma += n;
//				printf("%d %llu\n", cont, n);
			}
		}
		i++;
	}

	printf("%llu\n", soma);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld gcd (lld a, lld b){
	if (b == 0) return a;
	return gcd (b, a%b);
}

lld mmc (lld a, lld b){
	return (a/gcd(a,b))*b;
}


int main (){
	int n, t;
	scanf ("%d %d", &n, &t);

	lld x = 1;

	for (int i = 0; i < n; i++){
		lld aux;
		scanf ("%lld", &aux);
		x = mmc(x,aux);
	}

	//printf("%d\n", mmc(x,20));
	lld maximo = -1;
	lld indice = -1;
	for (int i = 1; i <= t; i++){
		//printf("%d\n", mmc(i,x));
		lld aux = mmc(i,x);
		if (aux <= t){
			if (maximo < aux){
				indice = i;
				maximo = aux;
			}
		}
	}
	printf("%lld\n", indice);

	return 0;
}
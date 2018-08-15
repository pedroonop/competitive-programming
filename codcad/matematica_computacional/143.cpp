#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int x1, x2, y1, y2;

	long long int cont = 0;
	for (int i = 0; i < n; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		cont += (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}

	printf("%lld\n", cont);

	return 0;
}
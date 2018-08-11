#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, m;
	scanf("%d %d", &n, &m);
	int a[200002];
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
	}

	int free = m;
	for (int i = 0; i < n; i++){
		if (free > a[i]){
			printf("0 ");
			free -= a[i];
			continue;
		}
		int cont = 1;
		a[i] -= free;
		cont += a[i] / m;
		free = m - (a[i] % m);
		printf("%d ", cont);
	}
	printf("\n");

	return 0;
}
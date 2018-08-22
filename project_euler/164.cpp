#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

llu M[30][30][30];

llu f(int n, int x1, int x2){
	if (n == 0) return 1;
	if (M[n][x1][x2]) return M[n][x1][x2];
	llu cont = 0;
	for (int i = 9 - x1 - x2; i >= 0; i--){
		cont += f(n - 1, x2, i);
	}
	M[n][x1][x2] = cont;
	return cont;
}

int main(){

	int n;
	scanf("%d", &n);

	llu cont = 0;
	for (int i = 1; i <= 9; i++){
		cont += f(n - 1, 0, i);
	}
	printf("%llu\n", cont);

	return 0;
}
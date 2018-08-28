#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

llu M[4][100001];

llu pra2(int n, int m){
	if (n > 2 * m) return 0;
	if (n > m) return m + m - n + 1;
	return n - 1;
}

llu pra3(int n, int m){
	if (n > 3 * m) return 0;
	llu cont = 0;
	for (int i = 1; i <= m; i++){
		cont += pra2(n - i, m);
	}
	return cont;
}

int main(){

	int n, m;

	scanf("%d %d", &n, &m);

	printf("%llu\n", pra3(n, m));

	return 0;
}
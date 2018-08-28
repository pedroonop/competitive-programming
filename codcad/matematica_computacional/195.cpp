#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

int main(){

	int n, a, b, c, d, e, f, g;

	scanf("%d %d %d %d %d %d %d %d", &n, &a, &b, &c, &d, &e, &f, &g);

	a -= d + e;
	b -= d + f;
	c -= e + f;

	int cont = a + b + c + d + e + f + g;

	if (cont != n){
		printf("S\n");
	}
	else{
		printf("N\n");
	}

	return 0;
}
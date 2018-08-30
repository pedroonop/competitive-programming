#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second

int main(){

	double l, c, r1, r2;
	scanf("%lf %lf %lf %lf", &l, &c, &r1, &r2);

	double aux = 2 * sqrt(r1 * r2) + r1 + r2;

	if (l >= aux || c >= aux) printf("S\n");
	else printf("N\n");

	return 0;
}
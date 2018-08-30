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
#define EPS 0.00001

int main(){

	double l, c, R, r;

	scanf("%lf %lf %lf %lf", &l, &c, &R, &r);

	while (l > EPS){
		double x1, y1, x2, y2;
		x1 = y1 = R;
		x2 = l - r;
		y2 = c - r;

		double distancia = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

		if (max(2 * R, 2 * r) > l || max(2 * R, 2 * r) > c) printf("N\n");
		else if (distancia >= R + r) printf("S\n");
		else printf("N\n");
		
		scanf("%lf %lf %lf %lf", &l, &c, &R, &r);
	}


	return 0;
}
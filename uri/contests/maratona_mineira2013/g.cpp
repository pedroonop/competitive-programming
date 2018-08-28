#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)
#define EPS 0.000001

int main(){

	double a, b;
	scanf("%lf %lf", &a, &b);

	while (a >	 EPS){
		double x = (a + b - sqrt(a * a + b * b - a * b)) / 6;

		printf("%.4lf %.4lf\n", x, (a - 2 * x) * (b - 2 * x) * x);

		scanf("%lf %lf", &a, &b);
	}

	return 0;
}
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
#define EPS 0.000001

int main(){

	double d, vf, vg;

	while (scanf("%lf %lf %lf", &d, &vf, &vg) == 3){
		if (12 / vf + EPS >= (sqrt(12 * 12 + d * d) / vg)){
			printf("S\n");
		}
		else{
			printf("N\n");
		}
	}


	return 0;
}
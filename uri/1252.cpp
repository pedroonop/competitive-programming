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
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define MAXN 10010

int m;

bool compare (int a, int b){
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (abs(a)%m == abs(b)%m){
		if (abs(a)%2 == 1 && abs(b)%2 == 1) return a > b;
		if (abs(a)%2 == 0 && abs(b)%2 == 0) return a < b;
		return abs(a)%2 > abs(b)%2;
	}
	return abs(a)%m < abs(b)%m;
}


int main (){
	int n;
	while (scanf ("%d %d", &n, &m) == 2){
		printf ("%d %d\n", n,m);
		if (n == 0) break;
		int v[n];
		go(i,n){
			scanf ("%d", &v[i]);
		}
		sort(v,v+n, compare);
		go(i,n){
			printf("%d\n", v[i]);
		}
	}
	return 0;
}

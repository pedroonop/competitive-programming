#include <bits/stdc++.h>
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
#define MAXN 1000000
using namespace std;

int v[MAXN];
vi pt;
vi st;
int main () {
	int n;
	scanf ("%d", &n);
	lld sum = 0;
	go(i,n){
		scanf ("%d", &v[i]);
		sum += v[i];
	}
	if (sum%3){
		printf("0\n");
		return 0;
	}
	lld t1 = sum/3;
	lld t2 = t1*2;
	sum = 0;
	go(i,n-1){
		sum += v[i];
		if (sum == t1) pt.push_back(i);
		if (sum == t2) st.push_back(i);
	}
	//printf("%lu %lu\n", pt.size(), st.size());
	lld ans = 0;
	go(i,pt.size()){
		ans += (st.end() - upper_bound(st.begin(),st.end(),pt[i]));
	}
	printf("%lld\n", ans);
	return 0;
}

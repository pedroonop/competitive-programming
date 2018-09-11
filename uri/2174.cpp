#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define vvii vector <vii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define MAXN 10001

set<string> se;

int main (){
	string s, x;
	int t;
	cin >> t;
	while (t--){
		cin >> s;
		se.insert(s);
	}
	printf("Falta(m) %lu pomekon(s).\n", 151-se.size());
	return 0;
}

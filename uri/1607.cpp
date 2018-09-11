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

int dist (char a, char b){
	if (a > b) a -= 26;
	return b-a;
}


int main (){
	string s, x;
	int t;
	cin >> t;
	while (t--){
		cin >> s >> x;
		int ans = 0;
		for (int i = 0; i < s.size();i++){
			ans += dist(s[i],x[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

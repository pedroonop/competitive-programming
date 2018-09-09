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
#define MAXN 15485863
#define M 10000031

string s, x;

lld memo[15][2];

lld dp (int d, bool pos_certa, string s){
	if (d == (int)s.size()) return 0;
	int n = s.size();
	lld ans = 0;
	lld &r = memo[d][pos_certa];
	if (r != -1) return r;
	for (int i = 0; i <= 9; i++){
		if (pos_certa && i+'0' > s[d]){break;}
		if (pos_certa && i+'0' == s[d]){
			ans += i*(atoi(s.substr(d+1).c_str())+1);
			ans += dp(d+1, pos_certa, s);
			break;
		}
		ans += (dp(d+1,  pos_certa && i+'0' == s[d], s) + i*pow(10,n-d-1));
	}
	//printf ("ans = %lld\n", ans);
	return r = ans;
}


int main (){
	cin >> s >> x;
	lld ans = 0;
	for (char x : s){
		ans += (x-'0');
	}
	ms(memo,-1);
	lld ans1 = dp(0,1,x);
	ms(memo,-1);
	ans1 -= dp(0,1,s);
	ans1 += ans;
	printf ("%lld\n", ans1);
	return 0;
}

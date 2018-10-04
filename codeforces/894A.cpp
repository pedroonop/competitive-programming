#include <bits/stdc++.h>
#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define MAXN 100100
using namespace std;

int n;
string v;
int memo[110][2][2][2];
int dp(int i, bool q1, bool a, bool q2){
	if (q1 && a && q2) return 1;
	if (i == n) return 0;
	
	int &ans = memo[i][q1][a][q2];
	if (ans != -1) return ans;
	
	if (v[i] == 'Q' and !q1) return ans =  dp(i+1,!q1,a,q2)+dp(i+1,q1,a,q2);
	if (v[i] == 'Q' and q1 and a) return ans = dp(i+1,q1,a,!q2)+dp(i+1,q1,a,q2);
	if (v[i] == 'A' and q1 and !a) return ans = dp(i+1,q1,!a,q2)+dp(i+1,q1,a,q2);
	
	return ans = dp(i+1,q1,a,q2);
}


int main (){
	ms(memo,-1);
	cin >> v;
	n = v.size();
	printf("%d\n", dp(0,false,false,false));
	return 0;
}

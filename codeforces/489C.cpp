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
#define INF_LLD 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define MAXN 10000000
using namespace std;

int n, m;


bool flag = false;

string x;
int memo[1001][1001];
int dp (int i, int k){
	//printf("memo = %d\n", memo[i][k]);
	if (flag) return 1;
	if (i == n && k == 0){
		flag = true;
		return 0;
	}
	if (i == n && k != 0) return 1;
	if (k < 0) return 1;
	int ans = 1;
	//printf("%d %d\n", i, k);
	if (memo[i][k] != -1){
		//printf("ENTROU\n");
		return memo[i][k];
	}
	if (i != 0){
		for (int j = 0; j <= 9; j++){
			//ans = min (ans, (mult[i]*j)+dp(i+1, k-j));
			if (!dp(i+1, k-j)){
				x.push_back('0'+j);
				ans = 0;
			}
		}
	}
	else{
		for (int j = 1; j <= 9; j++){
			if (!dp(i+1, k-j)){
				x.push_back('0'+j);
				ans = 0;
			}
		}
	}
	return memo[i][k] = ans;
}

string y;
int dp2 (int i, int k){
	if (flag) return 1;
	if (i == n && k == 0){
		flag = true;
		return 0;
	}
	if (i == n && k != 0) return 1;
	if (k < 0) return 1;
	int ans = 1;
	//printf("%d %d\n", i, k);
	if (memo[i][k] != -1){
		//printf("ENTROU\n");
		return memo[i][k];
	}
	for (int j = 9; j >= 0; j--){
		//ans = min (ans, (mult[i]*j)+dp(i+1, k-j));
		if (!dp2(i+1, k-j)){
			y.push_back('0'+j);
			ans = 0;
		}
	}
	
	return memo[i][k] = ans;
}



int main (){
	//ms(memo,-1);
	printf("%d\n", 3 << 1);
	memset (memo, -1, sizeof memo);
	scanf ("%d %d", &n, &m);
	if (n*9 < m || (n > 1 && m == 0)){
		printf("-1 -1\n");
		return 0;
	}
	dp(0,m);
	ms(memo,-1);
	flag = false;
	dp2(0,m);
	if (!x.size()) x = "0";
	if (!y.size()) y = "0";
	
	//printf ("%d ", dp2(0,m));
	
	reverse(y.begin(),y.end());
	reverse(x.begin(),x.end());
	cout << x << " ";
	cout << y << endl;
	//printf("%d\n", dp2(0,""));
	return 0;	
}

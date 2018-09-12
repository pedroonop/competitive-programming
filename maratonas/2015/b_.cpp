#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 201000
#define go(i,n) for (int i = 0; i < (int) n; i++)
#define goK(i,n,k) for (int i = 1; i <= (int) n-k; i++)
#define lld long long int
using namespace std;

int n, c;
int v[MAXN];
int memo[2][MAXN];
int pred[2][MAXN];

int com[MAXN];

int dp (int i, bool compra){
	if (i == n) return 0;
	
	int &ans = memo[compra][i];
	if (ans != -1) return ans;
	if (compra){
		return ans = max(dp(i+1,false)+v[i], dp(i+1,true));
	}
	return ans = max(dp(i+1,false), dp(i+1,true)-v[i]-c);
	
}

int main (){
	memset(memo,-1,sizeof memo);
	scanf ("%d %d", &n, &c);
	go(i,n){
		scanf ("%d", &v[i]);
		com[i] = v[i]+c;
	}
	printf ("%d\n",dp(0,0));
	
	return 0;
}

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
#define MAXN 10000000
using namespace std;

int n,m;
int v[100];

int memo[51][51][51][51];

int dp (int i, int pegos, int imaior, int imenor){
	if (i == m && !pegos) return fabs(v[imaior]-v[imenor]);
	if (i == m && pegos) return INF;
	if (!pegos) return fabs(v[imaior]-v[imenor]);
	
	int &r = memo[i][pegos][imaior][imenor];
	if (r != -1) return r;
	
	
	int novoMaior;
	int novoMenor;
	
	
	if (v[imaior] <= v[i]) novoMaior = i;
	else novoMaior = imaior;
	if (v[imenor] >= v[i]) novoMenor = i;
	else novoMenor = imenor;
	
	if (pegos == n){
		imaior++;
		imenor++;
	}
	return r = min (dp(i+1, pegos-1, novoMaior, novoMenor), dp(i+1, pegos, imaior, imenor));
}


int main (){
	memset(memo,-1, sizeof memo);
	scanf ("%d %d", &n, &m);
	go(i,m){
		scanf ("%d", &v[i]);
	}
	//printf("%d\n", v[8]);
	printf("%d\n",dp(0,n, 0, 0));
	return 0;
}

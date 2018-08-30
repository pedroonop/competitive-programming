#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 10010
#define go(i,n) for (int i = 1; i <= (int) n; i++)
#define goK(i,n,k) for (int i = 1; i <= (int) n-k; i++)
#define lld long long int
using namespace std;
int bit1 [MAXN];
int bit2 [MAXN];


void update (int i, int val, int bit[]){
	if (i <= 0) return;
	for (; i <= MAXN; i += (i&-i)){
		bit[i] += val;
	}
}

int busca (int i, int bit[]){
	int ans = 0;
	for (; i; i -= (i&-i)){
		ans += bit[i];
	}
	return ans;
}



int main (){
	int n, op, a, b, c;
	scanf ("%d", &n);
	go(i,n){
		scanf ("%d %d %d", &op, &a, &b);
		if (op){
			scanf ("%d", &c);
			update (a,c,bit1);
			update (b+1, -c,bit1);
			update (a, (a-1)*c,bit2);
			update (b+1, -c*b,bit2);
		}
		else{
			int ans = (busca(b,bit1)*b) - busca(b,bit2);
			ans -= (busca(a-1, bit1)*(a-1)) - busca(a,bit2);
			printf ("%d\n",ans);
		}
	}
	return 0;
}

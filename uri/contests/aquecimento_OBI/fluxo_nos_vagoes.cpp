#include <bits/stdc++.h>
#define MAXN 100010
#define vi vector <int>
#define ii pair <int,int>
#define iii pair <ii,int>
#define vii vector<ii>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define lld long long int
using namespace std;

lld bit[MAXN];



void update (int i, int val){
	for (; i <= MAXN; i += (i&-i)){
		bit[i] += val;
	}
}

lld query (int i){
	lld ans = 0;
	for (; i; i -= (i&-i)){
		ans += bit[i];
	}
	return ans;
}



int main (){
	int n, m, op, a,b,c,d;
	scanf ("%d %d", &n, &m);
	while (m--){
		scanf ("%d", &op);
		if (op == 1){
			scanf ("%d %d", &a, &b);
			//a--;
			update(a,b);
		}
		else{
			scanf ("%d %d %d %d", &a, &b, &c, &d);
			if (a > b) swap (a,b);
			if (c > d) swap (c,d);
			if (a > c){
				swap (a,c);
				swap (b,d);
			}
			if (c <= b){
					d = max (d, b);
					printf ("%lld\n", query(d)-query(a-1));
			}
			else{
				printf ("%lld\n", (query(b)-query(a-1))+(query(d)-query(c-1)));
			}
		}
	}
	
	return 0;
}

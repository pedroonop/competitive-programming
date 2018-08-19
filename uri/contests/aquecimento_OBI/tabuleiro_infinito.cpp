#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 305100
#define vi vector <int>
#define ii pair <int,int>
#define iii pair <ii,int>
#define vii vector<ii>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define lld long long int
#define iic pair <ii, char>
using namespace std;
queue <ii> q;
map <int,int> seen;
int main (){
	int e,d;
	scanf ("%d %d", &d, &e);
	q.push(ii(0,0));
	while (!q.empty()){
		ii x = q.front();
		q.pop();
		if (x.ss > d || x.ss < -e) continue;
		if (seen[x.ss]) continue;
		seen[x.ss] = 1;
		if (x.ss == -1 || x.ss == 1){
			printf ("%d\n", x.ff);
			return 0;
		}
		q.push(ii(x.ff+1, x.ss-e));
		q.push(ii(x.ff+1, x.ss+d));
	}
	printf ("IMPOSSIVEL\n");
	return 0;
}

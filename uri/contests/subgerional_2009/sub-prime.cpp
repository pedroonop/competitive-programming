#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 100010
#define go(i,n) for (int i = 0; i < (int) n; i++)
#define lld long long int
using namespace std;
int v[11220];


int main (){
	int cont = 0;
	int n, x, a, b, c;
	while (scanf ("%d %d", &x, &n) == 2){
		if (n == 0 && x == 0) break;
		cont++;
		go(i,x){
			scanf ("%d", &v[i+1]);
		}
		go(i,n){
			scanf ("%d %d %d", &a, &b, &c);
			v[a] -= c;
			v[b] += c;
		}
		bool flag = true;
		go(i,x){
			if (v[i+1] < 0){
				printf ("N\n");
				flag = false;
				break;
			}
		}
		if (flag) printf ("S\n");
	}
	return 0;
}

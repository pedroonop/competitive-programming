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
using namespace std;

int v[MAXN];

int main (){
	int n;
	while (scanf ("%d", &n) == 1){
		if (n == 0) return 0;
		go(i,n){
			scanf ("%d", &v[i]);
		}
		v[0] = v[n];
		v[n+1] = v[1];
		
		int cont = 0;
		go(i,n){
			if ((v[i] > v[i+1] && v[i] > v[i-1]) || (v[i] < v[i+1] && v[i] < v[i-1])){
				cont++;
			}
		}
		printf ("%d\n", cont);
	}
	return 0;
}

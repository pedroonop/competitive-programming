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

set <int> s1;
set <int> s2;


int main (){
	int n, m, a;
	while (scanf ("%d %d", &n, &m) == 2){
		s1.clear();
		s2.clear();
		if (n == m && m == 0) break;
		go(i,n){
			scanf ("%d", &a);
			s1.insert(a);
		}
		go(i,m){
			scanf ("%d", &a);
			s2.insert(a);
		}
		int cont1 = 0, cont2 = 0;
		for (int u : s1){
			if (s2.find(u) == s2.end()) cont1++;
		}
		for (int u : s2){
			if (s1.find(u) == s1.end()) cont2++;
		}
		printf ("%d\n", min(cont1, cont2));
	}
	return 0;
}

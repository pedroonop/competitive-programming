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

int main (){
	int h1, m1, h2, m2;
	
	while (scanf ("%d %d %d %d", &h1, &m1, &h2, &m2) == 4){
		if (h1 == m1 && m1 == h2 && h2 == m2 && m2 == 0) break;
		int ans = 0;
		while (m1 != m2){
			ans++;
			m1++;
			if (m1 >= 60){
				m1 = 0;
				h1++;
			}
		}
		h1 %= 24;
		//printf ("h1 = %d   h2 = %d\n", h1,h2);
		while (h1 != h2){
			//printf("aa\n");
			ans += 60;
			h1++;
			if (h1 >= 24){
				h1 = 0;
				//h1++;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

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

bool comp(ii a, ii b){
	return a.ss < b.ss;
}

int main(){

	int n;

	while (scanf("%d", &n) == 1){
		ii inter[1000001];

		go (i, n){
			scanf("%d %d", &inter[i].ff, &inter[i].ss);
		}

		sort(inter, inter + n, comp);

		int cont = 0;
		int last = -1;

		for (int i = 0; i < n; i++){
			if (inter[i].ff > last){
				cont++;
				last = inter[i].ss;
			}
		}

		printf("%d\n", cont);		
	}


	return 0;
}
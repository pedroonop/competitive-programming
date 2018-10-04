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
#define MAXN 100100
using namespace std;


lld bit[MAXN];
map<int,int> c;
vi v;


void update (int i, int val){
	for (; i <= MAXN; i += (i&-i))bit[i] += val;

}

lld query (int i){
	lld ans = 0;
	for (; i; i -= (i&-i)) ans += bit[i];
	return ans;
}



int main (){
	int n, q;
	scanf ("%d", &n);
	v.resize(n);
	go(i,n){
		scanf ("%d", &v[i]);
		
	}
	scanf ("%d", &q);
	sort(v.begin(),v.end());
	/*
	int indice = 1;
	go(i,n){
		if (c.find(v[i]) == c.end())
			c[v[i]] = indice++;
		update (c[v[i]], 1);
		//printf("%d -> %d\n", v[i], c[v[i]]);
	}*/
	
	go(i,q){
		int aux;
		scanf ("%d", &aux);
		if (aux < v[0]){
			printf("0\n");
			continue;
		}
		cout <<  (upper_bound(v.begin(),v.end(),aux)-v.begin()) << endl;
		
		
	}
	return 0;
}

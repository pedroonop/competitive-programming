#include <bits/stdc++.h>
#define ii pair <int, int>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
using namespace std;
#define MAXN 100010
#define go(i,n) for (int i = 0; i < (int) n; i++)
//int vetor[MAXN];

vector <ii> v;
int main (){
	int n;
	ii aux;
	scanf ("%d", &n);
	go(i,n){
		scanf ("%d %d", &aux.ff, &aux.ss);
		v.push_back(aux);
	}
	sort(v.begin(), v.end());
	//int maior = v[0].ss;
	int menor = v[v.size()-1].ss;
	for (int i = v.size()-2; i >= 0; i--){
		if (v[i].ss > menor){
			printf ("Happy Alex\n");
			return 0;
		}
		if (v[i].ss < menor) menor = v[i].ss;
	}
	printf ("Poor Alex\n");
	return 0;
}

#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define vii vector<ii>
#define lld long long int
using namespace std;
vii notas;

int main (){
	int n, k, a,b;
	scanf ("%d %d", &n, &k);
	k--;
	for (int i = 0; i < n; i++){
		scanf ("%d %d", &a, &b);
		notas.push_back(ii(-a, b));
	}
	sort(notas.begin(), notas.end());
	int ans = -1;
	for (int i = k; i >= 0; i--){
		if (notas[i].first == notas[k].first && notas[i].second == notas[k].second) ans++;
	}
	for (int i = k; i < n; i++){
		if (notas[i].first == notas[k].first && notas[i].second == notas[k].second) ans++;
	}
	//printf ("%d %d\n", notas[k].first, notas[k].second);
	printf ("%d\n", ans);
	return 0;
}

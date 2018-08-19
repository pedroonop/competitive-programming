#include <bits/stdc++.h>
#define MAXN 100001
#define vi vector <int>
#define ff first
#define ss second
using namespace std;
int v[MAXN];
map <int, int> m[101];
int main (){
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		scanf ("%d", &v[i]);
		m[v[i]][i] = i;
	}
	//int inicio, fim;
	bool flag;
	for (int i = 0; i < n-1; i++){
		flag = false;
		int menor_indice = MAXN;
		//printf ("vi = %d  tam = %lu\n", v[i], m[v[i]].size());
		for (int j = v[i]; j <= 100; j++){
			if (m[j].upper_bound(i) != m[j].end() && v[m[j].upper_bound(i)->ss] > v[i]){
				if (menor_indice > m[j].upper_bound(i)->ss ) menor_indice = m[j].upper_bound(i)->ss; 
				//printf ("%d ", j);
				flag = true;
				//break;
			}
		}
		if (!flag) printf ("* ");
		else printf ("%d ", v[menor_indice]);
	}
	printf ("*\n");
	return 0;
}

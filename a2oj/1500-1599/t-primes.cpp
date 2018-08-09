#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000100
#define lld long long int

bool crivo[MAXN];

void preprocess (){
	crivo[1] = true;
	for (int i = 2; i <= MAXN; i++){
		if (!crivo[i]){
			for (int j = 2; j*i <= MAXN; j++){
				crivo[j*i] = 1;
			}
		}
	}
}


int main (){
	int n;
	lld a, temp;
	preprocess();
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		scanf ("%lld", &a);
		temp = sqrt(a);
		if (temp * temp != a){
			printf ("NO\n");
			continue;
		}
		if (!crivo[temp]){
			printf ("YES\n");
		}
		else{
			printf ("NO\n");
		}
	}
	
	return 0;
}

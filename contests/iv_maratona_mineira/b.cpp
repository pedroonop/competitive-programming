#include <bits/stdc++.h>

using namespace std;

int main (){
	int a, b;

	scanf ("%d %d", &a, &b);
	if (b > a) swap (a,b);
	int cont = 0;
	while ((a/2)+7 > b){
		cont++;
		a++;
		b++;
	}
	printf("%d\n", cont);
	return 0;
}
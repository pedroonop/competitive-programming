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

int main(){

	int a, b, c;

	while (scanf("%d %d %d", &a, &b, &c) == 3){
		if (a != b && a != c){
			printf("A\n");
		}
		else if (b != a && b != c){
			printf("B\n");
		}
		else if (c != a && c != b){
			printf("C\n");
		}
		else{
			printf("*\n");
		}		
	}


	return 0;
}
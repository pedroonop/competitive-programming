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
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){

	int fats[] = {1, 2, 6, 24, 120, 720, 5040, 40320};

	int n;
	scanf("%d", &n);

	int atual = 7;
	int cont = 0;
	while (n > 0){
		cont += n / fats[atual];
		n = n % fats[atual];
		atual--;
	}

	printf("%d\n", cont);

	return 0;
}
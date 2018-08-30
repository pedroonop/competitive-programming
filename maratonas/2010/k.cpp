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

char tab[100001];

int main(){
	int n;
	char c;
	int qtd;

	scanf("%d" ,&n);

	while (n != 0){
		qtd = 0;

		for (int i = 0; i < n; i++){
			scanf(" %c" ,&tab[i]);
			if (tab[i] == '.') qtd++;
		}

		bool flag = false;

		for (int i = 1; i < n; i++){
			if (tab[i] == 'X' && tab[i-1] == 'X'){
				flag = true;
			}
		}

		if (!flag){
			for (int i = 0; i < n - 2; i++){
				if (tab[i] == 'X' && tab[i + 2] == 'X'){
					flag = true;
				}
			}
		}

		if (!flag && (qtd % 2 != 0)) flag = true;

		flag ? printf("S\n") : printf("N\n");

		scanf("%d" ,&n);
	}


	return 0;
}
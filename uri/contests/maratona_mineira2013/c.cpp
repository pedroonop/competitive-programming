#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

int main(){

	int k;
	scanf("%d", &k);

	while (k--){
		int n;
		scanf("%d", &n);

		int v[1100000];

		for (int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		int i = 0, j = 1;

		int sum = v[i];
		int cont = 0;

		while (i < n && j <= n){
			if (j == n && sum < 42){
				break;
			}
			if (sum == 42){
				i = j;
				j = i + 1;
				cont ++;
				if (i < n) sum = v[i];
			}
			else if(sum < 42){
				sum += v[j];
				j++;
			}
			else{
				sum -= v[i];
				i++;
			}
		}		
		printf("%d\n", cont);
	}



	return 0;
}
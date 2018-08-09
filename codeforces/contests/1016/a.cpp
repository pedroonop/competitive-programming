#include <bits/stdc++.h>
using namespace std;
int vetor[200001];

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf ("%d", &vetor[i]);
	}
	int temp = m;
	int temp2;
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans = 0;
		temp2 = vetor[i];
		vetor[i] -= temp;
		if (vetor[i] < 0) temp -= temp2;
		else{
			if (vetor[i] == 0){
				ans++;
				temp = m;
			}
			else{
				ans += m/vetor[i];
				temp = m%vetor[i];
				//printf ("temp = %d vetor = %d\n", temp, vetor[i]);
				if (temp == 0){
					temp = m;
					ans++;
				}
			}
		}
		//printf ("temp = %d\n", temp);
		printf ("%d ", ans);
	}
	printf ("\n");
	return 0;
}

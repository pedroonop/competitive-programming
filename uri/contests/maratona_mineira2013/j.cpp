#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

int n;
int recarga[1001];
int peso[1001];

bool percorrer_horario(int i){
	int n = recarga[i];
	for (int j = i; j < n - 1; j++){
		if (n < peso[j]) return false;
		n += recarga[j + 1] - peso[j];
	}
	if (n < peso[n - 1]) return false;
	n += recarga[0] - peso[n - 1];
	for (int j = 0; j < i; j++){
		if (n < peso[j]) return false;
		n += recarga[j + 1] - peso[j];
	}
}

int main(){

	scanf("%d", &n);


	for (int i = 0; i < n; i++){
		scanf("%d", &recarga[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &peso[i]);
	}

	return 0;
}
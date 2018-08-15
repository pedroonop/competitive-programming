#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v;
	v.push_back(-1);
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int M[100000];
	M[0] = 0;
	for (int i = 1; i <= n; i++){
		M[i] = M[i - 1] + v[i];
	}

	int maior = 0;
	for (int i = 3; i <= n; i++){
		if (v[i] < M[i - 1]) maior = max(maior, i);
	}

	printf("%d\n", maior);

	return 0;
}
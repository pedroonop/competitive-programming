#include <bits/stdc++.h>

using namespace std;

int bit[101];

void update(int i, int value){
	for (; i <= 100; i += (i & -i)) bit[i] = bit[i] ^ value;
}

int query(int i){
	int result = 0;
	for (; i; i -= (i & -i)) result = result ^ bit[i];
	return result;
}

int main(){

	int v[] = {-1, 1, 2, 3, 4, 5};

	for (int i = 1; i <= 5; i++){
		update(i, v[i]);
	}

	while (1){
		int op, a, b;
		scanf("%d", &op);
		scanf("%d %d", &a, &b);
		if (op){
			printf("%d\n", query(b) ^ query(a - 1));
		}
		else{
			update(a, v[a] ^ b);
			v[a] = b;
		}
	}

	return 0;
}
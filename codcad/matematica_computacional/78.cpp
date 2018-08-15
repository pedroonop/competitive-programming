#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
	if (b == 0) return a;
	return mdc(b, a % b);
}

int main(){

	int mdc_ = 0;

	int n;
	scanf("%d", &n);

	int aux;
	for (int i = 0; i < n; i++){
		scanf("%d", &aux);
		mdc_ = mdc(mdc_, aux);
	}

	printf("%d\n", mdc_);

	return 0;
}
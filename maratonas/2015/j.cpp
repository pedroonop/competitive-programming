/*
* @Author: Pedro Torres
* @Date:   2018-09-10 19:31:02
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-09-10 19:38:42
*/

#include <bits/stdc++.h>

#define MAXN 501

int pt[MAXN];

using namespace std;

int maior(int n){
	int max_ = -1;
	int w = -1;
	for (int i = 0; i < n; i++){
		if (pt[i] >= max_){
			max_ = pt[i];
			w = i;
		}
	}

	return w + 1;
}

int main(){
	int j, r, g;
	int aux;

	scanf("%d %d" ,&j ,&r);

	for (int i = 0; i < j * r; i++){
		scanf("%d" ,&aux);
		pt[i % j] += aux;
	}

	printf("%d\n" ,maior(j));

	return 0;
}
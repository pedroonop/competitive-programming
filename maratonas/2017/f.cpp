/*
* @Author: Pedro Torres
* @Date:   2018-09-13 18:55:51
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-09-13 19:04:18
*/

#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

bool comp(int a, int b){
	return a > b;
}

int pt[MAXN];

int main(){
	int n, k;

	int ans = 0;
	int last; 

	scanf("%d %d" ,&n ,&k);

	for (int i = 0; i < n; i++){
		scanf("%d" ,&pt[i]);
	}

	sort(pt, pt + n, comp);

	last = pt[k - 1];

	ans = k;

	for (int i = k; i < n; i++){
		if (pt[i] != last) break;
		ans++;
	}

	printf("%d\n" ,ans);

	return 0;
}
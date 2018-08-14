/*
* @Author: Pedro Torres
* @Date:   2018-08-12 17:15:37
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-08-14 09:20:05
*/

#include <bits/stdc++.h>

using namespace std;


int main(){
	int n;
	int a, b, c;
	int dp[4001];

	scanf("%d %d %d %d" ,&n ,&a ,&b, &c);

	dp[0] = 0;

	int x, y, z;

	for(int i = 1; i <= n; i++){
		
		x = y = z = -1;

		if(i - a >= 0){
			x = dp[i - a];
		}
		if(i - b >= 0){
			y = dp[i - b];
		}
		if(i - c >= 0){
			z = dp[i - c];
		}

		if(x == -1 && y == -1 && z == -1){
			dp[i] = -1;
		}
		else{
			dp[i] = max(max(x, y), z) + 1;
		}

	}

	printf("%d\n" ,dp[n]);

	return 0;
}
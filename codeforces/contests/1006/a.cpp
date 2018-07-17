/*
* @Author: pedrotorres
* @Date:   2018-07-17 10:43:12
* @Last Modified by:   pedrotorres
* @Last Modified time: 2018-07-17 10:43:18
*/

#include <bits/stdc++.h>

using namespace std;

int arr[1001];

int main(){
	int n;
	
	scanf("%d" ,&n);
	
	for(int i = 0; i < n; i++){
		scanf("%d" ,&arr[i]);
	}
	
	for(int i = 0; i < n; i++){
		if(arr[i] % 2 == 0){
			arr[i]--;
		} 
	}
	
	for(int i = 0; i < n; i++){
		printf("%d " ,arr[i]);
	}
	
	printf("\n");
	
	return 0;
	
}

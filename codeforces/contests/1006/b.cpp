/*
* @Author: pedrotorres
* @Date:   2018-07-17 10:42:48
* @Last Modified by:   pedrotorres
* @Last Modified time: 2018-07-17 11:37:48
*/

#include <bits/stdc++.h>

#define ii pair<int, int>
#define pb push_back

using namespace std;

vector<ii> arr;
vector<ii> ans;

int main(){
	int n, k;
	int profit;

	scanf("%d %d" ,&n ,&k);

	int v;

	for(int i = 0; i < n; i++){
		scanf("%d" ,&v);
		arr.pb(ii(v, i));
	}

	sort(arr.rbegin(), arr.rend());

	for(int i = 0; i < k; i++){
		ans.pb(ii(arr[i].second, arr[i].first));
		profit += arr[i].first;
	}

	sort(ans.begin(), ans.end());

	int last = 0;
	int sum = 0;

	printf("%d\n" ,profit);

	for(int i = 0; i < ans.size(); i++){
		v = ans[i].first - last + 1;
		if(i == ans.size() - 1 && v + sum != n){
			v += n - sum - v;
		}
		printf("%d " ,v);
		sum += v;
		last = ans[i].first + 1;
	}

	printf("\n");

	return 0;
}

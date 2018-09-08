#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))

int main(){
	string dig;
	int k;
	stack<int> S;

	while(cin >> dig >> k){
		S = stack<int>();
		S.push(dig[0] - '0');

		for (int i = 1; i < (int) dig.size(); i++){
			while (!S.empty() && (dig[i] - '0') < S.top() && k != 0){
				S.pop();
				k--;
			}
			S.push(dig[i] - '0');
		}

		while (k != 0){
			S.pop();
			k--;	
		}

		list<int> ans;

		while (!S.empty()){
			ans.push_front(S.top());
			S.pop();
		}

		list<int>::iterator it;

		for (it = ans.begin(); it != ans.end(); it++){
			printf("%d" ,*it);
		}

		printf("\n");
	}





	return 0;
}
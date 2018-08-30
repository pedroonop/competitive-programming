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

int main(){
	int n;
	int alt[5];
	char v[] = {'A', 'B', 'C', 'D', 'E'};
	char op = '$';

	scanf("%d" ,&n);

	while(n != 0){
		for(int j = 0; j < n; j++){
			char op = '$';
			for (int i = 0; i < 5; i++){
				scanf("%d" ,&alt[i]);
			}

			for (int i = 0; i < 5; i++){
				if (alt[i] <= 127){
					if(op == '$'){
						op = v[i];
					}
					else{
						op = '*';
						break;
					}
				}
			}

			if(op == '$'){
				op = '*';
			}

			printf("%c\n" ,op);		
		}
		scanf("%d" ,&n);
	}




	return 0;
}
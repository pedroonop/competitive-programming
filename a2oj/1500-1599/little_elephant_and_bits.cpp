#include <bits/stdc++.h>
#define ii pair <int, int>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
using namespace std;
#define MAXN 100010
#define go(i,n) for (int i = 0; i < (int) n; i++)
//int vetor[MAXN];

int main (){
	string s;
	cin >> s;
	bool flag = false;
	for (int i = 0; i < (int) s.size(); i++){
		if (!flag && s[i] == '0'){
			s[i] = '2';
			flag = true;
		}
	}
	if (flag){
		for (char u : s){
			if (u != '2') printf ("%c", u);
		}
	}
	else{
		for (int i = 0; i < (int) s.size()-1; i++){
			printf ("%c", s[i]);
		}
	}
	printf ("\n");
	return 0;
}

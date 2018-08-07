#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
#define MAXN 100010
#define go(i,n) for (int i = 0; i < (int) n; i++)
//int vetor[MAXN];

int main (){
	string s;
	cin >> s;
	for (int i = 0; i < (int) s.size(); i++){
		if (s[i] == 'r') printf ("%d\n", i+1);
	}
	for (int i = s.size()-1; i >= 0; i--) if (s[i] == 'l') printf ("%d\n", i+1);
	return 0;
}

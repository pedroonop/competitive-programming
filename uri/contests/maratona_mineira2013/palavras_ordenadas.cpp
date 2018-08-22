#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 10010
#define go(i,n) for (int i = 1; i < (int) n; i++)
#define goK(i,n,k) for (int i = 1; i <= (int) n-k; i++)
using namespace std;

int main (){
	int n;
	string s;
	cin >> n;
	while (n--){
		bool flag = false;
		cin >> s;
		string z = s;
		if (s[0] >= 'A' && s[0] <= 'Z') s[0] = s[0]-'A'+'a';
		go(i,s.size()){
			if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i]-'A'+'a';
			//printf ("%c", s[i]);
			if (s[i] <= s[i-1]){
				cout << z << ": N\n";
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << z << ": O\n";
		
	}
	return 0;
}

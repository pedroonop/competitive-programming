#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 1001
#define vi vector <int>
#define ii pair <int,int>
#define iii pair <ii,int>
#define vii vector<ii>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define lld long long int
#define iic pair <ii, char>
using namespace std;
unsigned char x;
char gera_chac (char chave, char origem){
	x = origem;
	x += (chave-'a');
	if (x  > 'z') x -= 26;
	return x;
}


int main (){
	string s, x;
	int n;
	cin >> s;
	cin >> n;
	int tam = s.size();
	getline(cin,x);
	while (n--){
		getline (cin,x);
		int cont = 0;
		bool comeco = true;
		bool flag = true;
		for (char c : x){
			if (c == ' '){printf(" ");comeco = true; flag = true; continue;}
			if (comeco && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')){ flag = false; comeco = false;}
			else comeco = false;
			if (flag) {
				printf ("%c", gera_chac(s[cont%tam], c));
			}
			else{
				printf ("%c", c);
				continue;
			}
			cont++;
		}
		printf("\n");
	}
	return 0;
}

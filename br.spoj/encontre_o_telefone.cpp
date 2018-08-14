#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAXN 9
map <char, int> m;
int main (){
	for (char i = 'A'; i <= 'C'; i++){
		m[i] = 2;
	}
	for (char i = 'D'; i <= 'F'; i++){
		m[i] = 3;
	}
	for (char i = 'G'; i <= 'I'; i++){
		m[i] = 4;
	}
	for (char i = 'J'; i <= 'L'; i++){
		m[i] = 5;
	}
	for (char i = 'M'; i <= 'O'; i++){
		m[i] = 6;
	}
	for (char i = 'P'; i <= 'S'; i++){
		m[i] = 7;
	}
	for (char i = 'T'; i <= 'V'; i++){
		m[i] = 8;
	}
	for (char i = 'W'; i <= 'Z'; i++){
		m[i] = 9;
	}
	string s;
	while (cin >> s){
		for (char c: s){
			if (m.find(c) != m.end()) printf ("%d", m[c]);
			else printf ("%c", c);
		}
		printf ("\n");
	}
	return 0;
}

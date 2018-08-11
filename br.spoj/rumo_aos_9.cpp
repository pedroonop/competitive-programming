#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAXN 9

int main (){
	string s;
	while (cin >> s){
		if (s == "0") break;
		int num = 0, cont = 0;
		for (char c : s){
			num += (c-'0');
		}
		cont++;
		if (num % 9 != 0){
			cout << s << " is not a multiple of 9." << '\n';
			continue;
		}
		string x;
		x.resize(10, '0');
		int indice = 0;
		while (num > 9){
			x.clear();
			//printf ("num = %d\n", num);
			indice = 0;
			cont++;
			x.resize(10,'0');
			while (num > 9){
				x[indice] = '0'+(num%10);
				indice++;
				num /= 10;
			}
			x[indice] = '0'+(num%10);
			num = 0;
			for (char c : x){
				num += (c-'0');
			}
		}
		cout << s << " is a multiple of 9 and has 9-degree " << cont << "." << '\n';
	}
	return 0;
}

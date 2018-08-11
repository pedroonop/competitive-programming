#include <bits/stdc++.h>

using namespace std;

int participa[2000];

int main(){

	int n, m, q;
	cin >> n >> m >> q;

	string s, t;
	cin >> s >> t;
	s = "_" + s;
	t = "_" + t;

	int termin[2000];
	int comeca[2000];

	for (int i = 0; i < m; i++){
		termin[i] = 0;
	}
	for (int i = m; i <= n; i++){
		termin[i] = termin[i - 1];
		bool flag = true;
		for (int j = 1; j <= m; j++){
			if (t[j] != s[j + i - m]){
				flag = false;
				break;
			}
		}
		if (flag){
			termin[i]++;
			for (int j = 1; j <= m; j++){
				participa[j + i - m]++;
			}
		}
	}

	for (int i = n; i > n - m + 1; i--){
		comeca[i] = 0;
	}
	for (int i = n - m + 1; i > 0; i--){
		comeca[i] = comeca[i + 1];
		bool flag = true;
		for (int j = 1; j <= m; j++){
			if (t[j] != s[j + i - 1]){
				flag = false;
				break;
			}
		}
		if (flag) comeca[i]++;
	}
	comeca[0] = 0;
	comeca[n + 1] = 0;

	for (int i = 1; i <= n; i++){
		cout << s[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; i++){
		cout << comeca[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++){
		cout << termin[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++){
		cout << participa[i] << " ";
	}
	cout << endl;

	int a, b;
	for (int i = 0; i < q; i++){
		cin >> a >> b;
		cout << comeca[a] << " - " << comeca[b + 1] << " - " << participa[b] << endl;
		int cont = comeca[a] - comeca[b + 1];
		if (participa[b] > participa[b + 1]){
			cont--;
		}
		cout << cont << endl;
	}

	return 0;
}

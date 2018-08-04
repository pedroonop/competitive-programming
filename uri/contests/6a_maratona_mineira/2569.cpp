#include <bits/stdc++.h>

using namespace std;

int main(){

	string a, b;
	char op;
	cin >> a >> op >> b;

	for (int i = 0; i < (int)a.size(); i++){
		if (a[i] == '7'){
			a[i] = '0';
		}
	}
	for (int i = 0; i < (int)b.size(); i++){
		if (b[i] == '7'){
			b[i] = '0';
		}
	}

	int c;
	if (op == '+'){
		c = stoi(a) + stoi(b);
	}
	else{
		c = stoi(a) * stoi(b);
	}

	string c_ = to_string(c);
	for (int i = 0; i < (int)c_.size(); i++){
		if (c_[i] == '7'){
			c_[i] = '0';
		}
	}

	c = stoi(c_);
	cout << c << endl;

	return 0;
}
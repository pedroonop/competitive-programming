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

int cubo[6][3][3];

void rodar_face_horario(int face){
	int aux = cubo[face][0][0];
	cubo[face][0][0] = cubo[face][2][0];
	cubo[face][2][0] = cubo[face][2][2];
	cubo[face][2][2] = cubo[face][0][2];
	cubo[face][0][2] = aux;

	aux = cubo[face][0][1];
	cubo[face][0][1] = cubo[face][1][0];
	cubo[face][1][0] = cubo[face][2][1];
	cubo[face][2][1] = cubo[face][1][2];
	cubo[face][1][2] = cubo[face][0][1];
}

void rodar_face_ahorario(int face){
	int aux = cubo[face][0][0];
	cubo[face][0][0] = cubo[face][0][2];
	cubo[face][0][2] = cubo[face][2][2];
	cubo[face][2][2] = cubo[face][2][0];
	cubo[face][2][0] = aux;

	aux = cubo[face][0][1];
	cubo[face][0][1] = cubo[face][1][2];
	cubo[face][1][2] = cubo[face][2][1];
	cubo[face][2][1] = cubo[face][1][0];
	cubo[face][1][0] = aux;
}

void f(){
	int a, b, c;
	a = cubo[2][2][0];
	b = cubo[2][2][1];
	c = cubo[2][2][2];

	cubo[2][2][0] = cubo[4][0][2];
	cubo[2][2][1] = cubo[4][1][2];
	cubo[2][2][2] = cubo[4][2][2];

	cubo[4][0][2] = cubo[3][2][2];
	cubo[4][1][2] = cubo[3][2][1];
	cubo[4][2][2] = cubo[3][2][0];

	cubo[3][2][2] = cubo[5][2][2];
	cubo[3][2][1] = cubo[5][1][2];
	cubo[3][2][0] = cubo[5][0][2];

	cubo[5][2][2] = a;
	cubo[5][1][2] = b;
	cubo[5][0][2] = c;

	rodar_face_ahorario(0);
}

void F(){
	f(); f(); f();
}

void b(){
	int a, b, c;
	a = cubo[2][0][0];
	b = cubo[2][0][1];
	c = cubo[2][0][2];

	cubo[2][0][0] = cubo[5][2][0];
	cubo[2][0][1] = cubo[5][1][0];
	cubo[2][0][2] = cubo[5][0][0];

	cubo[5][2][0] = cubo[3][0][2];
	cubo[5][1][0] = cubo[3][0][1];
	cubo[5][0][0] = cubo[3][0][0];

	cubo[3][0][2] = cubo[4][0][0];
	cubo[3][0][1] = cubo[4][1][0];
	cubo[3][0][0] = cubo[4][2][0];

	cubo[4][0][0] = a;
	cubo[4][1][0] = b;
	cubo[4][2][0] = c;

	rodar_face_horario(1);
}

void B(){
	b(); b(); b();
}

void u(){
	int a, b, c;
	a = cubo[0][0][0];
	b = cubo[0][0][1];
	c = cubo[0][0][2];

	cubo[0][0][0] = cubo[5][0][0];
	cubo[0][0][1] = cubo[5][0][1];
	cubo[0][0][2] = cubo[5][0][2];

	cubo[5][0][0] = cubo[1][0][2];
	cubo[5][0][1] = cubo[1][0][1];
	cubo[5][0][2] = cubo[1][0][0];

	cubo[1][0][0] = cubo[4][0][0];
	cubo[1][0][1] = cubo[4][0][1];
	cubo[1][0][2] = cubo[4][0][2];

	cubo[4][0][0] = c;
	cubo[4][0][1] = b;
	cubo[4][0][2] = a;

	rodar_face_ahorario(2);
}

void U(){
	u(); u(); u();
}

void d(){
	int a, b, c;
	a = cubo[0][2][0];
	b = cubo[0][2][1];
	c = cubo[0][2][2];

	cubo[0][2][0] = cubo[4][2][2];
	cubo[0][2][1] = cubo[4][2][1];
	cubo[0][2][2] = cubo[4][2][0];

	cubo[4][2][0] = cubo[1][2][0];
	cubo[4][2][1] = cubo[1][2][1];
	cubo[4][2][2] = cubo[1][2][2];

	cubo[1][2][0] = cubo[5][2][2];
	cubo[1][2][1] = cubo[5][2][1];
	cubo[1][2][2] = cubo[5][2][0];

	cubo[5][2][0] = a;
	cubo[5][2][1] = b;
	cubo[5][2][2] = c;

	rodar_face_horario(3);
}

void D(){
	d(); d(); d();
}

void r(){
	int a, b, c;
	a = cubo[0][0][2];
	b = cubo[0][1][2];
	c = cubo[0][2][2];

	cubo[0][0][2] = cubo[2][0][2];
	cubo[0][1][2] = cubo[2][0][2];
	cubo[0][2][2] = cubo[2][0][2];

	cubo[2][0][2] = cubo[1][2][2];
	cubo[2][1][2] = cubo[1][1][2];
	cubo[2][2][2] = cubo[1][0][2];

	cubo[1][2][2] = cubo[3][2][2];
	cubo[1][1][2] = cubo[3][1][2];
	cubo[1][0][2] = cubo[3][0][2];

	cubo[3][2][2] = a;
	cubo[3][1][2] = b;
	cubo[3][0][2] = c;

	rodar_face_horario(4);
}

void R(){
	r(); r(); r();
}

void l(){
	int a, b, c;
	a = cubo[0][0][0];
	b = cubo[0][1][0];
	c = cubo[0][2][0];

	cubo[0][0][0] = cubo[3][2][0];
	cubo[0][1][0] = cubo[3][1][0];
	cubo[0][2][0] = cubo[3][0][0];

	cubo[3][2][0] = cubo[1][2][0];
	cubo[3][1][0] = cubo[1][1][0];
	cubo[3][0][0] = cubo[1][0][0];

	cubo[1][2][0] = cubo[2][0][0];
	cubo[1][1][0] = cubo[2][1][0];
	cubo[1][0][0] = cubo[2][2][0];

	cubo[2][0][0] = a;
	cubo[2][1][0] = b;
	cubo[2][2][0] = c;

	rodar_face_ahorario(5);
}

void L(){
	l(); l(); l();
}

bool match(){
	go (face, 6){
		go (linha, 3){
			go (coluna, 3){
				if (cubo[face][linha][coluna] != face)
					return false;
			}
		}
	}
	return true;
}

void char2func(char c){
	if (c == 'f') f();
	else if (c == 'F') F();
	else if (c == 'b') b();
	else if (c == 'B') B();
	else if (c == 'u') u();
	else if (c == 'U') U();
	else if (c == 'd') d();
	else if (c == 'D') D();
	else if (c == 'r') r();
	else if (c == 'R') R();
	else if (c == 'l') l();
	else if (c == 'L') L();
}

void apply_pattern(string s){
	for (char c : s){
		char2func(c);
	}
}

int main(){

	go (face, 6){
		go (linha, 3){
			go (coluna, 3){
				cubo[face][linha][coluna] = face;
			}
		}
	}

	string s;
	cin >> s;

	apply_pattern(s);
	int cont = 1;

	while (!match()){
		cont++;
		apply_pattern(s);
	}

	cout << cont << endl;

	return 0;
}
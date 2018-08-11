#include <bits/stdc++.h>

using namespace std;

#define f float
#define ponto pair<f, f>
#define x first
#define y second
#define sqrt_2 1.414213562
#define EPS 0.0000001

void mostrar_ponto(ponto p){
	cout << "x: " << p.x << " y: " << p.y << endl;
}

ponto operator+(const ponto &a, const ponto &b){
	return ponto(a.x + b.x, a.y + b.y);
}

ponto operator-(const ponto &a, const ponto &b){
	return ponto(a.x - b.x, a.y - b.y);
}

double escalar(ponto a, ponto b){
	return a.x * b.x + a.y * b.y;
}

double modulo(ponto a){
	return sqrt(escalar(a, a));
}

double vetorial(ponto a, ponto b){
	return a.x * b.y - a.y * b.x;
}

bool colinear(ponto a, ponto b, ponto c){
	return vetorial(b - a, c - b) == 0;
}

bool condicao1(ponto p[]){
	ponto a = p[2] - p[1], b = p[3] - p[1];
	if (vetorial(p[2] - p[1], p[3] - p[2]) <= 0) return false;
	f cosseno = escalar(a, b) / (modulo(a) * modulo(b));
	return 0 < cosseno && cosseno < 1;
}

bool condicao2(ponto p[]){
	return fabs(modulo(p[2] - p[1]) - modulo(p[3] - p[1])) < EPS;
}

bool condicao3(ponto p[]){
	return colinear(p[2], p[3], p[4]) && colinear(p[3], p[4], p[5]);
}

bool condicao4(ponto p[]){
	return modulo(p[4] - p[2]) == modulo(p[5] - p[3]);
}

bool condicao5(ponto p[]){
	return modulo(p[3] - p[2]) > modulo(p[5] - p[4]);
}

bool condicao6(ponto p[]){
	ponto a = p[4] - p[6], b = p[5] - p[7], c = p[2] - p[3];
	f cosseno1 = escalar(a, c) / (modulo(a) * modulo(c)), cosseno2 = escalar(b, c) / (modulo(b) * modulo(c));
	return cosseno1 == 0 && cosseno2 == 0;
}

bool condicao7(ponto p[]){
	return modulo(p[4] - p[6]) == modulo(p[5] - p[7]);
}

bool condicao8(ponto p[]){
	return vetorial(p[3] - p[2], p[1] - p[3]) * vetorial(p[3] - p[2], p[6] - p[3]) < 0;
}

int main(){

	ponto p[10];
	for (int i = 1; i <= 7; i++){
		scanf("%f %f", &p[i].x, &p[i].y);
	}

	if (false){
		for (int i = 1; i <= 8; i++){
			cout << i << " ";
		}
		cout << endl;
		cout << condicao1(p) << " ";
		cout << condicao2(p) << " ";
		cout << condicao3(p) << " ";
		cout << condicao4(p) << " ";
		cout << condicao5(p) << " ";
		cout << condicao6(p) << " ";
		cout << condicao7(p) << " ";
		cout << condicao8(p) << " ";
		cout << endl;		
	}

	if (condicao1(p) &&
		condicao2(p) &&
		condicao3(p) &&
		condicao4(p) &&
		condicao5(p) &&
		condicao6(p) &&
		condicao7(p) &&
		condicao8(p)){
		printf("S\n");
	}
	else{
		printf("N\n");
	}
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a >= b + c || b >= a + c || c >= a + b){
		printf("n\n");
	}
	else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b){
		printf("r\n");
	}
	else if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b){
		printf("o\n");
	}
	else{
		printf("a\n");
	}

	return 0;
}
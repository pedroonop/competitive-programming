/*
* @Author: Pedro Torres
* @Date:   2018-08-26 19:37:04
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-08-26 19:37:08
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int e, s;
	double valor_conta, deixou;

	scanf("%d %d %lf %lf" ,&e ,&s ,&valor_conta, &deixou);

	printf("%.2lf\n" ,(valor_conta - (deixou * s)) / (e - s));

	return 0;
}
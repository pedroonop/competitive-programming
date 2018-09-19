#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c;

	scanf("%d %d %d" ,&a ,&b ,&c);

	printf("%d\n" ,min(min(2 * b + 4 * c, 2 * a + 2 * c), 4 * a + 2 * b));

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
int main(){

	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

	printf("%d\n",!(
		x1 > x4 || x3 > x2 || y1 > y4 || y3 > y2
		));

	return 0;
}
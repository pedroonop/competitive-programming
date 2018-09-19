#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, b, x, y;
	int ans = 0;

	scanf("%d %d" ,&n, &b);

	if (n >= b){
		x = 0;
		y = n;
	}

	while (1){
		if (n + ans > b) break;
		y = n;
		ans += n;
		n--;
		
		if (n + ans > b) break;
		ans += n;
		x = n;
		x = ((ans + y) % n) + 1;
		if (n + ans > b) break;
		ans += n;
		y -= n;
		n--;

		if (n + ans > b) break;
		ans += n;
		x -= n;
	}

	// if (ans < b) ans += 

	printf("%d %d\n" ,x ,y);

	printf("%d\n" ,ans);

	return 0;
}
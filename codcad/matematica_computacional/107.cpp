#include <stdio.h>
#include <math.h>

int main(){

	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if ((c % a != 0) || (a == b) || (c == d)){
		printf("-1\n");
	}
	else{
		int aux = sqrt(c) + 1;
		int aux2 = ~(1<<31);
		bool flag = false;
		for (int i = 1; i <= aux; i++){
			if (c % i == 0){
				if (i % a == 0 && i % b != 0 && d % i != 0){
					aux2 = i;
					flag = true;
					break;
				}
				if ((c / i) % a == 0 && (c / i) % b != 0 && d % (c / i) != 0){
					if ((c / i) < aux2){
						aux2 = (c / i);
						flag = true;
					}
				}
			}
		}
		if (flag){
			printf("%d\n", aux2);
		}
		else{
			printf("-1\n");
		}
	}

	return 0;
}
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define vi vector<int>
#define MAXN 9
#define ii pair <int, int>
#define vvc vector<vector<char> >
#define x first
#define y second

int main (){
	int n;
	string t1,t2;
	scanf ("%d", &n);
	cin >> t1;
	cin >> t2;
	int score1 = 0, score2 = 0;
	int pode1 = n, pode2 = n;
	for (int i = 0, cont = 0; i < n; i++){
		if (score1 > score2+pode2) {
			printf ("%d\n", cont);
			return 0;
		}
		if (t1[i] == 'o') score1++;
		pode1--;
		cont++;
		if (score1 > score2+pode2) {
			printf ("%d\n", cont);
			return 0;
		}
		if (score2 > score1+pode1){
			printf ("%d\n", cont);
			return 0;
		}
		if (t2[i] == 'o') score2++;
		pode2--;
		cont++;
		if (score2 > score1+pode1){
			printf ("%d\n", cont);
			return 0;
		}
	}
	printf ("Empate\n");
	return 0;
}

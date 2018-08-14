#include <bits/stdc++.h>
using namespace std;
#define MAX_N 300010

char T[MAX_N], P[MAX_N], P2[MAX_N];
int b[MAX_N], n, m; 
int match1[MAX_N];
int match2[MAX_N];
int sum1[MAX_N];
int sum2[MAX_N];
int ultimo;
void kmpPreprocess(char P[]) { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

void kmpSearch(char P[], bool flag) { // this is similar as kmpPreprocess(), but on string T
  int i = 0, j = 0; // starting values
  while (i < n) { // search through string T
    while (j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == m) { // a match found when j == m
      //printf("P is found at index %d in T\n", i - j);
      if (flag) match1[i-j] = 1;
      else{ match2[i-j] = 1; ultimo = i-j;}
      j = b[j]; // prepare j for the next possible match
} } }


int main (){
	//strcpy (T, "gogoa");
	//strcpy (P, "go");
	int x;
	while (scanf ("%s", T) == 1){
		memset (match1, 0, sizeof(match1));
		memset (match2, 0, sizeof(match2));
		ultimo = -1;
		scanf ("%s", P);
		scanf ("%s", P2);
		n = strlen(T);
		x = m = strlen(P);
		kmpPreprocess(P);
		kmpSearch(P, true);
		m = strlen(P2);
		kmpPreprocess(P2);
		kmpSearch(P2, false);
		int temp = 0;
		for (int i = 0; i < n; i++){
			temp += match1[i]; sum1[i] = temp;
			//printf ("%d ", sum1[i]);
		}
		//printf ("\n");
		temp = 0;
		//for (int i = 0; i < n; i++) {temp += match2[i]; sum2[i] = temp; /*printf ("%d ", sum2[i]);*/}
		int ans = 0;
		//if (ultimo != -1)
		for (int i = 0; i < n; i++)
			if(match2[i])ans += sum1[i];
		
		printf ("%d\n", ans);
	}
	return 0;
	
}

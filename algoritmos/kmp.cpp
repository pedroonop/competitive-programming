#include <cstdio>
#include <cstring>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010

char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess(string P) { // call this before calling kmpSearch()
	m = P.size();
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

bool kmpSearch(string T, string P) { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0; // starting values
	n = T.size(); m = P.size();
	while (i < n) { // search through string T
	    while (j >= 0 && T[i] != P[j]){ j = b[j]; } // if different, reset j using b
	    i++; j++; // if same, advance both pointers
	    if (j == m) { // a match found when j == m
	    	//printf("j = %d\n",j );
	      printf("P is found at index %d in T\n", i - j);
	      j = b[j]; // prepare j for the next possible match
	      return true;
		} 
	}
	return false; 
}



int main() {
  
  return 0;
}

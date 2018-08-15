#include <bits/stdc++.h>
using namespace std;
string s;
int memo[5003];
int dp (int i){
    if (i >= s.size()-1){
        return 1;
    }
    if (s[i] == '0') return 0;
    if (memo[i] != -1) return memo[i];
    if ((s[i]-'0')*10 + s[i+1]-'0' <= 26){
        return memo[i] = dp(i+1)+dp(i+2);
    }
    return memo[i] = dp(i+1);
}



int main(){
    while(cin >> s){
        if (s == "0") break;
        memset (memo, -1, sizeof(memo));
        s += 'Z';
        printf ("%d\n", dp(0));
    }
    return 0;
}
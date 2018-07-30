#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int merge_sort(vector<int> &v){
	
	int inv=0;
	if(v.size()==1) return 0;
	
	vector<int> u1, u2;
	for(int i = 0; i < (int)v.size()/2;i++){
		u1.push_back(v[i]);
	}
	for(int i=v.size()/2;i< (int) v.size();i++){
	 	u2.push_back(v[i]);
	}	
	inv+=merge_sort(u1);
	inv+=merge_sort(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	int ini1=0, ini2=0;
	for(int i = 0;i < (int)v.size();i++){
		if(u1[ini1]<=u2[ini2]){
			v[i]=u1[ini1];
			ini1++;
		}
		else{
			v[i]=u2[ini2];
			ini2++;
			inv+=u1.size()-ini1-1;
		}
	}
	
	return inv;
}

int main (){
	int n, aux;
	vector <int> v;
	while (true){
		scanf ("%d", &n);
		v.clear();
		if (n == 0) break;
		for (int i = 0; i < n; i++){
			scanf ("%d", &aux);
			v.push_back(aux);
		}
		if (merge_sort(v) % 2 == 0) printf ("Carlos\n");
		else printf ("Marcelo\n");
	}
	return 0;
}

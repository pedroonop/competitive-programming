#include <bits/stdc++.h>
#define MAXN 1000005
#define MID(l,r)     ((l+r) >> 1)
using namespace std;

int tree[4*MAXN];
int vetor[MAXN];

void build (int node, int left, int right){
    if (left == right){
        tree[node] = vetor[left];
        return;
    }
    int mid = MID(left, right);
    build (2*node+1, left, mid);
    build (2*node+2, mid+1, right);
    tree[node] = tree[2*node+1]+tree[2*node+2];
    
}

void update (int node, int left, int right, int i){
    if (left == right){
        tree[node] = vetor[left];
        return;
    }
    if (i >= left && i <= right){
        int mid = MID(left, right);
        if (i <= mid) update(2*node+1, left, mid, i);
        else update (2*node+2, mid+1, right, i);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}

int query(int node,int left ,int right ,int lq , int rq){ //O(logN) para buscar na segtree
	if(right < lq || left > rq)
		return 0;
		
	if(left >= lq && right <= rq)
		return tree[node];
	
	int mid = MID(left,right);
	int p1 = query(2*node+1,left,mid,lq,rq); 
	int p2 = query(2*node+2,mid+1,right,lq,rq);
	return p1+p2;
}

int main (){
	int n,q, a, b;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		vetor[i] =  1;
	}
	build (0, 0, n-1);
	scanf ("%d", &q);
	while (q--){
		scanf ("%d %d", &a, &b);
		if (!a){
			b--;
			if (vetor[b]) {
				vetor[b] = 0;
				update (0, 0, n-1, b);
			}
		}
		else{
			
			int inicio, fim, ans, mid;
			inicio = 0;
			fim = n-1;
			ans = -1;
			while (inicio <= fim){
				mid = MID (inicio,fim);
				if (query(0,0,n-1,0, mid) >= b){
					fim = mid-1;
					ans = mid+1;
				}
				else{
					inicio = mid+1;
				}
			}
			printf ("%d\n", ans);
		}
	}
	return 0;
}

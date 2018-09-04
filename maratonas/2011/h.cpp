#include <bits/stdc++.h>

#define mid(l, r) 	       ((l + r) >> 1)

using namespace std;


typedef struct{
	int v[3];
}Node;


const int maxn  = 100000;
Node tree[4*maxn];
int lazy[4*maxn];
int arr[maxn];




void build(int node, int left ,int right){
	if(left == right){
		tree[node].v[1]++;
		//lazy[node] = 0;
		return;
	}
	
	int mid = mid(left,right);
	int esq = 2*node+1;
	int dir = 2*node+2;
	build(esq,left,mid);
	build(dir,mid+1,right);
	tree[node].v[0] = tree[esq].v[0] + tree[dir].v[0];
	//lazy[node] = 0;

}



void update_range( int node, int left, int right, int lq, int rq, int k){
  
  if( lazy[node] ){
  		int v[3];
  		go(i,3){
  			v[i] = tree[node].v[(i+lazy[node])%3];
  		}
		//tree[node] = (right-left+1)*lazy[node];
		
		if( left != right ){ // tem filhos
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		
		lazy[node] = 0;
	}
  
  if( right < lq || left > rq )  // se o intervalo [lq,rq] está fora [left, right]
		return ;
  
  if(left >= lq && right <= rq){ // se o intervalo [lq,rq] cobre totalmente [left, right]
		
		//tree[node] = (right-left+1)*k;
  		go(i,3){
  			tree[node].v[i] += k;
  			tree[node].v[i] %= 3;
  		}
		//printf("[%d - %d] = %d\n", left+1, right+1, tree[node]);
		if( left != right ){ // tem filhos
			lazy[2*node+1] += k;
			lazy[2*node+2] += k;
		}
		
	}else{
		
		int mid = mid(left,right);
		int esq = 2*node+1;
		int dir = 2*node+2;
		update_range(esq,left,mid,lq,rq, k); 
		update_range(dir,mid+1,right,lq,rq, k);
		go(i,3){
			tree[node].v[i] = tree[esq].v[i] + tree[dir].v[i];
		}
    	//tree[node] = tree[2*node+1] + tree[2*node+2];
		//printf("[%d - %d] = %d\n", left+1, right+1, tree[node]);
		
  }
  
}


int query(int node,int left ,int right ,int lq , int rq){
	
	if( lazy[node] ){
		tree[node] = (right-left+1)*lazy[node];
		
		if( left != right ){ // tem filhos
			lazy[2*node+1] = lazy[node];
			lazy[2*node+2] = lazy[node];
		}
		
		lazy[node] = 0;
	}
  
	if(right < lq || left > rq)
		return 0;
		
	if(left >= lq && right <= rq)
		return tree[node];
	
	int mid = mid(left,right);
	int p1 = query(2*node+1,left,mid,lq,rq); 
	int p2 = query(2*node+2,mid+1,right,lq,rq);
	
	return p1 + p2;
}



int main(){
	int n, q;
	int o;
	int a, b, k;
	
	//cin >> n >> q;
	scanf ("%d %d", &n, &q);


	for(int i = 0; i < n; i++) cin >> arr[i];
		
	build(0, 0, n-1);
		
	for(int i = 1; i <= q; i++){
		
		scanf("%d", &o);	
		
		if( o == 1){
			scanf("%d %d %d", &a, &b , &k);
			a--;
			b--;
			update_range(0, 0, n-1, a, b, k);
		}else{
			scanf("%d %d", &a, &b);
			a--;
			b--;
			printf("%d\n", query(0, 0, n-1, a, b) );
		}		
	}
		
}
 

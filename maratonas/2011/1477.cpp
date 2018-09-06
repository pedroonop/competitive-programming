#include <bits/stdc++.h>
#define go(i,n) for (int i = 0; i < (int)n; i++)

#define mid(l, r) 	       ((l + r) >> 1)

using namespace std;


typedef struct{
	int v[3];
}Node;


const int maxn  = 100000;
Node tree[4*maxn];
int lazy[4*maxn];
Node vazio;
int v[3];


int add (int a, int b){
	a += b;
	if (a >= 3) a -= 3;
	return a;
	
}



void build(int node, int left ,int right){
	if(left == right){
		tree[node].v[0]++;
		//lazy[node] = 0;
		return;
	}
	
	int mid = mid(left,right);
	int esq = 2*node+1;
	//int dir = 2*node+2;
	build(esq,left,mid);
	build(esq+1,mid+1,right);
	tree[node].v[0] = tree[esq].v[0] + tree[esq+1].v[0];
	//lazy[node] = 0;

}



void update_range( int node, int left, int right, int lq, int rq, int k){
  int esq = 2*node+1;
  //int dir = 2*node+2;
  if( lazy[node] ){
  		go(i,3){
  			//v[(i+lazy[node])%3] = tree[node].v[i];
  			v[add(i,lazy[node])] = tree[node].v[i];
  		}
  		go(i,3){
  			tree[node].v[i] = v[i];
  		}
		
		if( left != right ){ // tem filhos
			lazy[esq] = add(lazy[node],lazy[esq]);
			lazy[esq+1] = add(lazy[node],lazy[esq+1]);
		}
		
		lazy[node] = 0;
	}
  
  if( right < lq || left > rq )  // se o intervalo [lq,rq] está fora [left, right]
		return ;
  
  if(left >= lq && right <= rq){ // se o intervalo [lq,rq] cobre totalmente [left, right]
		
		//tree[node] = (right-left+1)*k;
  		go(i,3){
  			//v[(i+k)%3] = tree[node].v[i];
  			v[add(i,k)] = tree[node].v[i];
  		}
  		go(i,3){
  			tree[node].v[i] = v[i];
  		}
		//printf("[%d - %d] = %d\n", left+1, right+1, tree[node]);
		if( left != right ){ // tem filhos
			lazy[esq] = add(k,lazy[esq]);
			lazy[esq+1] = add(k,lazy[esq+1]);
		}
		
	}else{
		
		int mid = mid(left,right);
		//int esq = 2*node+1;
		//int dir = 2*node+2;
		update_range(esq,left,mid,lq,rq, k); 
		update_range(esq+1,mid+1,right,lq,rq, k);
		go(i,3){
			tree[node].v[i] = tree[esq].v[i] + tree[esq+1].v[i];
		}
    	//tree[node] = tree[2*node+1] + tree[2*node+2];
		//printf("[%d - %d] = %d\n", left+1, right+1, tree[node]);
		
  }
  
}


Node query(int node,int left ,int right ,int lq , int rq){
	int esq = 2*node+1;
	//int dir = 2*node+2;
	if( lazy[node] ){
		//tree[node] = (right-left+1)*lazy[node];
		go(i,3){
  			v[add(i,lazy[node])] = tree[node].v[i];
  		}
  		go(i,3){
  			tree[node].v[i] = v[i];
  		}
		if( left != right ){ // tem filhos
			lazy[esq] = add(lazy[esq],lazy[node]);
			lazy[esq+1] = add(lazy[esq+1],lazy[node]);
		}
		
		lazy[node] = 0;
	}
  
	if(right < lq || left > rq)
		return vazio;
		
	if(left >= lq && right <= rq)
		return tree[node];
	
	int mid = mid(left,right);
	Node p1 = query(esq,left,mid,lq,rq); 
	Node p2 = query(esq+1,mid+1,right,lq,rq);
	Node p3;

	go(i,3){
		p3.v[i] = p1.v[i] + p2.v[i];
	}

	return p3;
}



int main(){
	memset (vazio.v, 0, sizeof(vazio.v));
	int n, q;
	char op;
	int a, b;
	
	//cin >> n >> q;
	while (scanf ("%d %d", &n, &q) == 2){
		memset (tree, 0, sizeof(tree));
		memset (lazy, 0, sizeof(lazy));
		build(0, 0, n-1);
			
		for(int i = 1; i <= q; i++){
			
			scanf(" %c %d %d", &op, &a, &b);
			a--;
			b--;	
			
			if( op == 'M'){
				update_range(0, 0, n-1, a, b, 1);
			}else{
				//scanf("%d %d", &a, &b);
				Node aux = query(0,0,n-1, a,b);
				printf("%d", aux.v[0]);
				printf(" %d", aux.v[1]);
				printf(" %d", aux.v[2]);
				printf("\n");
				//printf("%d\n", query(0, 0, n-1, a, b) );
			}		
		}
		printf("\n");
	}
	 	
}
 

#include <bits/stdc++.h>
#define MAXN 300

using namespace std;


int n;
int g[MAXN][MAXN];
vector <int> pred;
vector <int> marc;

void dfs(int v, int t){
	marc[v]=1;
	if( pred[t] != -1) return;
	for(int j=1;j<n+1;j++){
	   if(g[v][j] > 0 && marc[j]==0){
	      pred[j]=v;
				dfs(j,t);	
	   }
	}
	
}

int FordFulkerson(int s, int t){
   
		int flow = 0;
			
    while (1){
      //printf ("a\n");
	    pred.assign(n+1, -1);
	    
	    marc.assign(n+1,  0); 
	     
      dfs(s,t);
     
	    if (pred[t]==-1) break;
     
      for (int i=t;pred[i]!=-1;i=pred[i]){
          g[pred[i]][i]--;
          //g[i][pred[i]]++;
      }
      
      flow++;
    }
    return flow;
}
         
         
int main(){
  
  int V, u,v, weight, m;
  int s,t;
  int cont = 0;
  while (scanf ("%d", &n) == 1){
	  cont++;
	  if (n == 0) break;
	  scanf("%d %d %d", &s, &t, &m);

	  memset(g, 0, sizeof g);
	  for (int i = 0; i < m; i++) {
		  scanf("%d %d %d",&u, &v, &weight);
		  g[u][v] = weight;
		  g[v][u] = weight;
	  }
	
		int ans = FordFulkerson(s, t);
		printf ("Network %d\n", cont);
		printf ("The bandwidth is %d.\n", ans);
	}
	return 0;
}

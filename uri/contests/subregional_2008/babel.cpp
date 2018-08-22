#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
using namespace std;

typedef struct Node{
    int tam;
    int inicial;
    bool operator<(const Node& rhs) const{
        return tam < rhs.tam;
    }
}Node;
map <string, int> m;
int indice = 1;
vector<vector <in> > g;

priority_queue <iii, vector<iii>, greater<iii> > pq;

int main (){
    int n;
    string a, b,c, inicial, final;
    while (cin >> n){
        if (n == 0) return 0;
        cin >> inicial >> final;
        indice = 1;
        m.clear();
        g.clear();
        pq = priority_queue <iii, vector<iii>, greater<iii> >();
        g.resize(100000);
        if (m.find(inicial) == m.end())m[inicial] = indice++;
        if (m.find(final) == m.end())m[final] = indice++;
        for (int i = 0; i < n; i++){
            cin >> a >> b >> c;
            if (m.find(a) == m.end())m[a] = indice++;
            if (m.find(b) == m.end())m[b] = indice++;
            Node aux;
            aux.tam = c.size();
            aux.inicial = c[0]-'a';
            g[m[a]].push_back(in(m[b],aux));
            g[m[b]].push_back(in(m[a],aux));
        }
        vector <int> x;
        x.resize(26);
        pq.push(iii(ii(0,m[inicial]), 26));
        vector<int> dist[27];
        for (int i = 0; i < 27; i++)
			dist[i].assign(100000, INF);
        
        for (int i = 0; i < 27;i++)
			dist[i][m[inicial]] = 0;
        while (!pq.empty()){
            iii x = pq.top();
            int u = x.ff.ss;
            int sx = x.ss;
            pq.pop();
            if (x.ff.ff > dist[sx][u]) continue;
            
            for (in s : g[u]){
				if (s.ss.inicial == sx){continue;}
                int v = s.ff;
                if (dist[sx][u]+ s.ss.tam < dist[s.ss.inicial][v]){
                    dist[s.ss.inicial][v] = dist[sx][u]+ s.ss.tam;
                    pq.push(iii(ii(dist[s.ss.inicial][v], v), s.ss.inicial));
                }
            }
        }
        int menor = INF;
        for (int i = 0; i < 26;i++){
			if (dist[i][m[final]] < menor) menor = dist[i][m[final]];
		}
        if (menor == INF)
            printf ("impossivel\n");
        else printf ("%d\n", menor);
    }
    return 0;
}

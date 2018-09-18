/*
* @Author: pedrotorres
* @Date:   2018-05-14 19:51:14
* @Last Modified by:   pedrotorres
* @Last Modified time: 2018-05-14 22:24:44
*/

#include <bits/stdc++.h>

using namespace std;

struct container{
	int conf[8];
	int custo;
};

struct less_container{
	bool operator() (container &a, container &b){
		return a.custo > b.custo;
	}
};

struct equal_container{
	bool operator() (const container &a, const container &b) const{
		for(int i = 0; i < 8; i++){
			if(a.conf[i] != b.conf[i]){
				return false;
			}
		}
		return true;
	}
};

struct container_hash {
    size_t operator() (const container& a) const {
        size_t hash = 0;
        size_t seed = 307;
        for(int i = 0; i < 8; i++){
        	hash += a.conf[i] * seed;
        	seed *= 349;
        }

        return hash;
    }
};

int destino[8];
priority_queue<container, vector<container>, less_container> pq;
unordered_set<container, container_hash, equal_container> visitados;

void new_conf(container atual, int x, int y){
	container to_add;

	// printf("%d %d %d\n", x, y, (int) pq.size());

	for(int i = 0; i < 8; i++){
		to_add.conf[i] = atual.conf[i];
	}

	to_add.conf[x] = atual.conf[y];
	to_add.conf[y] = atual.conf[x];


	if(visitados.find(to_add) == visitados.end()){
		to_add.custo = atual.custo + atual.conf[x] + atual.conf[y];
		pq.push(to_add);
	}

}

bool final_conf(container atual){
	for(int i = 0; i < 8; i++){
		if(atual.conf[i] != destino[i]){
			return false;
		}
	}
	return true;
}

int main(){
	container origem;

	for(int i = 0; i < 8; i++){
		scanf("%d" ,&origem.conf[i]);
	}

	for(int i = 0; i < 8; i++){
		scanf("%d" ,&destino[i]);
	}

	origem.custo = 0;

	pq.push(origem);

	while(!pq.empty()){
		container atual = pq.top();
		pq.pop();

		// print_container(atual);

		if(visitados.find(atual) != visitados.end()){
			continue;
		}
		visitados.insert(atual);

		if(final_conf(atual)){
			printf("%d\n" ,atual.custo);
			break;
		}

		new_conf(atual, 0, 1);
		new_conf(atual, 0, 4);

		new_conf(atual, 1, 2);
		new_conf(atual, 1, 5);

		new_conf(atual, 2, 3);
		new_conf(atual, 2, 6);

		new_conf(atual, 3, 7);

		new_conf(atual, 4, 5);

		new_conf(atual, 5, 6);

		new_conf(atual, 6, 7);
	}

	return 0;
}
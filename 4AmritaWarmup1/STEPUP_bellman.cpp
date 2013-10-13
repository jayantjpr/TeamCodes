#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class Graph{
	int V;
	vector< set<int> > adjList;
	vector<int> dist;
	
	public:
	Graph(int n){
		V = n;
		adjList.resize(V+1);
		dist.resize(V+1, 1);
	}

	void put(int a, int b){
		adjList[a].insert(b);
	}

	
	void bellman(){
		bool updated;
		for (int doit = 1; doit <= V; doit++){
			updated = false;
			for (int i = 1; i <= V; i++){
				for (set<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++){
					int temp = dist[i] + 1;
					if (dist[*it] < temp){
					       	dist[*it] = temp;
						updated = true;
					}
				}
			}
			if (!updated) break;
		}
		if (updated)
			printf("IMPOSSIBLE\n");
		else{
			printf("%d\n", *max_element(dist.begin()+1, dist.end()));
		}
	}
};

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int N, M;
		scanf("%d %d", &N, &M);

		Graph graph(N);
		for (int i = 0; i < M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			graph.put(a, b);
		}
		graph.bellman();
	}
	return 0;
}

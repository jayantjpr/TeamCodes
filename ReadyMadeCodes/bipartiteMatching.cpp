#include <cstdio>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Graph{
	int V;
	vector< set<int> > adjList;
	
	public:
	Graph(int n){
		V = n;
		adjList.resize(V+1);
	}

	virtual void put(int a, int b){
		adjList[a].insert(b);
	}

	bool bfs(int source, int destination, vector<int>& parent){
		queue<int> q;
		vector<bool> visited(V+1, false);
		
		q.push(source);
		visited[source] = true;
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(set<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++)
				if (!visited[*it]){
					visited[*it] = true;
					q.push(*it);
					parent[*it] = v;
					if (*it == destination) return true;
				}
		}
		return false;
	}

	int maximumFlow(int source, int destination){
		vector<int> parent(V+1);
		int maxFlow = 0;
		while (bfs(source, destination, parent)){
			for(int v = destination; v != source; v = parent[v]){
				adjList[parent[v]].erase(v);
				adjList[v].insert(parent[v]);
			}
			maxFlow += 1;
		}
		return maxFlow;
	}
};

class BipartiteGraph : public Graph{
	map<int, int> xToVertex, yToVertex;
	int count;
	int source;
	int destination;

	public:
	BipartiteGraph(int V) : Graph(2*V+1){
		source = 0;
		destination = 2*V+1;
		count = 1;

	}
	
	void put(int x, int y){
		map<int, int>::iterator it;
		int index1, index2;

		if ((it = xToVertex.find(x)) != xToVertex.end())
			index1 = it -> second;
		else{
			index1 = count++;
			xToVertex[x] = index1;
		}
		if ((it = yToVertex.find(y)) != yToVertex.end())
			index2 = it -> second;
		else{
			index2 = count++;
			yToVertex[y] = index2;
		}
		Graph::put(source, index1);
		Graph::put(index1, index2);
		Graph::put(index2, destination);
	}

	int mimimumVertexCover(){
		return Graph::maximumFlow(source, destination);			
	}
};

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int N;
		scanf("%d", &N);

		BipartiteGraph graph(N);
		for (int i = 0; i < N; i++){
			int X, Y;
			scanf("%d %d", &X, &Y);
			graph.put(X, Y);
		}
		printf("%d\n", graph.mimimumVertexCover());
	}
	return 0;
}

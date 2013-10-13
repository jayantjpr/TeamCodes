#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Graph{
	int V;
	vector< vector< pair<int, int> > > adjList;
	
	//for cycle detection
	vector< vector<int> >adjListBar;
	vector< pair<int, int> > finish;
	vector<bool> visit;
	
	//for bellman ford
	vector<int> dist;

	public:

	Graph(int n, int minVal){
		V = n;
		adjList.resize(n+1);
		adjListBar.resize(n+1);
		dist.resize(n+1, minVal);
		visit.resize(n+1, false);
		finish.clear();
	}


	void put(int a, int b, int w){
		adjList[a].push_back(make_pair(b, w));
		adjListBar[b].push_back(a);
	}

	int dfs(int source, int time){
		visit[source] = true;
		int finishTime = time+1;
		for (vector< pair<int, int> >::iterator it = adjList[source].begin(); it != adjList[source].end(); it++){
			if (!visit[it -> first]){
				finishTime = max(dfs(it->first, time+1), finishTime);
			}
		}
		finish.push_back(make_pair(finishTime, source));
		return finishTime+1;
	}

	bool detectCycle(){
		for (int i = 1, time = 0; i <= V; i++){
			if(!visit[i]) time = dfs(i, time);
		}
		sort(finish.begin(), finish.end(), greater< pair<int, int> >());
		
		visit.clear();
		visit.resize(V+1, false);
		for (vector< pair<int, int> >::iterator it = finish.begin(); it != finish.end(); it++){
			int source = it->second;
			if (!visit[source]){
				visit[source] = true;
				for (vector<int>::iterator it1 = adjListBar[source].begin(); it1 != adjListBar[source].end(); it1++){
					if (!visit[*it1]){
						return true;
					}
				}
			}
		}
		return false;
	}

	int bellman(){
		for (int doit = 1; doit <= V+2; doit++){
			for (int i = 1; i <= V; i++){
				for (vector< pair<int, int> >::iterator it = adjList[i].begin(); it != adjList[i].end(); it++){
					int temp = dist[i] + it->second;
					if (dist[it->first] < temp) dist[it->first] = temp;
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= V; i++) sum += dist[i];
		return sum;
	}

	void print(){
		for (int i = 1; i <= V; i++) printf("%d ", dist[i]);
		printf("\n");
	}
};

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int N, M, L;
		scanf("%d %d %d", &N, &M, &L);
		Graph graph(N, L);

		for (int i = 0; i < M; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			graph.put(b, a, c);
		}
		if (graph.detectCycle())
			printf("Inconsistent analysis.\n");
		else{
			printf("%d\n", graph.bellman());
			graph.print();
		}
	}
	return 0;
}

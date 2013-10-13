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
	vector< vector< pair<int, double> > > adjList;
	vector<double> dist;
	vector<bool> visit;

	public:

	Graph(int n){
		V = n;
		adjList.resize(n+1);
		dist.resize(n+1, -1.0);
		visit.resize(n+1, false);
	}

	void put(int a, int b, double w){
		adjList[a].push_back(make_pair(b, w));
		adjList[b].push_back(make_pair(a, w));
		//cout << a << " " << b << " " << w << endl;
	}

	void dijkstra(int source, int destination){
		priority_queue< pair<double, int> > q;
		q.push(make_pair(INT_MAX,source));
		//cout << source << " -2- " << INT_MAX << endl;

		while(!q.empty()){
		       	int v = q.top().second;
			double w = q.top().first;
			q.pop();
			//cout << v << " -1- " << w << endl;
			if (!visit[v]){
				visit[v] = true;
			       	dist[v] = w;
				if (v == destination) break;

				for (vector< pair<int, double> >::iterator it = adjList[v].begin(); it != adjList[v].end(); it++){
					if (!visit[it->first]){
						double temp = min(dist[v], it->second);
						if (dist[it->first] < temp){
						       dist[it->first] = temp;
						       q.push(make_pair(temp, it->first));
							//cout << it->first << " -2- " << temp << endl;
						}
					}
				}
			}
		}
	}

	double largestSafetyFactor(int source, int destination){
		dijkstra(source, destination);
		return dist[destination];
	}
};

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int N;
		scanf("%d", &N);
		Graph graph(N);
		
		int a, b;
		double w;
		scanf("%d %d %lf", &a, &b, &w);
		while(a != -1){
			graph.put(a, b, w);
			scanf("%d %d %lf", &a, &b, &w);
		}
		printf("%lf\n", graph.largestSafetyFactor(1, N));
	}

	return 0;
}

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

class Graph{
	int V;
	vector< vector< pair<int, ll> > > adjList;
	vector<ll> dist;
	vector<ll> sh;
	vector<ll> lg;
	vector<bool> visit;

	public:

	Graph(int n){
		V = n;
		adjList.resize(n);
		dist.resize(n, LLONG_MAX);
		sh.resize(n, LLONG_MAX);
		lg.resize(n, LLONG_MIN);
		visit.resize(n, false);
	}

	void put(int a, int b, ll w){
		adjList[a].push_back(make_pair(b, w));
		adjList[b].push_back(make_pair(a, w));
		//cout << a << " " << b << " " << w << endl;
	}

	void dijkstra(int source, int destination){
		priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > q;
		q.push(make_pair((ll)0,source));
		//cout << source << " -2- " << 0 << endl;

		while(!q.empty()){
		       	int v = q.top().second;
			ll w = q.top().first;
			q.pop();
			//cout << v << " -1- " << w << "(" << sh[v] <<"," << lg[v] << ")" << endl;
			if (!visit[v]){
				visit[v] = true;
			       	dist[v] = w;
				if (v == destination) break;

				for (vector< pair<int, ll> >::iterator it = adjList[v].begin(); it != adjList[v].end(); it++){
					if (!visit[it->first]){
						ll shPath = min(sh[v], it->second);
						ll lgPath = max(lg[v], it->second);
						ll diff = lgPath - shPath;
						if (diff < dist[it->first]){
						       dist[it->first] = diff;
						       lg[it->first] = lgPath;
						       sh[it->first] = shPath;
						       q.push(make_pair(diff, it->first));
						       //cout << it->first << " -2- " << diff << "(" << sh[it->first] <<"," << lg[it->first] << ")" << endl;
						}
					}
				}
			}
		}
	}

	ll smallestDiff(int source, int destination){
		dijkstra(source, destination);
		if (!visit[destination])
			return -1;
		return dist[destination];
	}
};

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int N, R;
		scanf("%d %d", &N, &R);
		Graph graph(N);
		
		int source, destination;
		scanf("%d %d", &source, &destination);
		while(R--){
			int a, b;
		       	ll w;
			scanf("%d %d %lld", &a, &b, &w);
			graph.put(a, b, w);
		}
		ll ans  = graph.smallestDiff(source, destination);
		if (ans == -1)
			printf("NO PATH\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}

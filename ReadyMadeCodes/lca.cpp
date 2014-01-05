#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define LOG2(x) (int)(log(x)/log(2))

#define MAX 100000

using namespace std;

class RMQ{
	vector<int> M;
	vector<int> *A;

	public:

	RMQ(vector<int> *A){
		this -> A = A;
		int len = A -> size();

		M.clear();
		M.resize(pow(2,LOG2(len)+2) + 10, -1);
		initialize(1, 0, len-1);
	}

	void initialize(int node, int b, int e)
	{
		if (b == e)
			M[node] = b;
		else
		{
			initialize(2 * node, b, (b + e) / 2);
			initialize(2 * node + 1, (b + e) / 2 + 1, e);
			if ((*A)[M[2 * node]] <= (*A)[M[2 * node + 1]])
				M[node] = M[2 * node];
			else
				M[node] = M[2 * node + 1]; 
		}
	}

	int query(int node, int b, int e, int i, int j)
	{
		int p1, p2;
		if (i > e || j < b)
			return -1;

		if (b >= i && e <= j)
			return M[node];
		p1 = query(2 * node, b, (b + e) / 2, i, j);
		p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);

		if (p1 == -1)
			return p2;
		if (p2 == -1)
			return p1;
		if ((*A)[p1] <= (*A)[p2])
			return p1;
		return p2;
	}

	int query(int i, int j){
		return query(1,0,A->size()-1, i, j);
	}
};

class Tree{
	vector<int> E;
	vector<int> L;
	vector<int> H;
	vector< vector<int> > adj;
	int N;
	RMQ *rmq;

	public:

	Tree(int N){
		this -> N = N;
		
		adj.clear(); 
		E.clear(); 
		L.clear(); 
		H.clear(); 

		adj.resize(N);
		H.resize(N);
	}
	
	void put(int parent, int child){
		adj[parent].push_back(child);
	}

	void compute(){
		dfs(0, 0);
		rmq = new RMQ(&L);
	}

	void dfs(int node, int height){
		H[node] = E.size();
		E.push_back(node);
		L.push_back(height);

		for (vector<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++){
			dfs(*it, height+1);
			E.push_back(node);
			L.push_back(height);
		}
	}


	int query(int u, int v){
		int index;
		if (H[u] < H[v])
			index = rmq -> query(H[u], H[v]);
		else 
			index = rmq -> query(H[u], H[v]);

		return E[index];
	}
};


int main(){
	int N;
	scanf("%d", &N);

	Tree tree(N);
	for (int i = 1; i <= N-1; i++){
		int parent;
		scanf("%d", &parent);
		tree.put(parent, i);
	}
	tree.compute();

	int M;
	scanf("%d",&M);

	int lca;
	scanf("%d", &lca);
	for(int i = 1; i < M; i++){
		int u;
		scanf("%d", &u);
		lca = tree.query(lca,u);
	}

	printf("%d", lca);
}




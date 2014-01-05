#include <cstdio>
#include <utility>
#include <cmath>

#define MAXN 10000
#define MAXIND 100000  		//(pow(2,(int)log2(MAXN)+2) + 10);

int N, A[MAXN], M[MAXIND];

void initialize(int node, int b, int e){
	if (b == e) M[node] = b;
	else{
		//compute the values in the left and right subtrees
		initialize(2 * node, b, (b + e) / 2);
		initialize(2 * node + 1, (b + e) / 2 + 1, e);

		//search for the minimum value in the first and second half of the interval
		if (A[M[2 * node]] <= A[M[2 * node + 1]])
			M[node] = M[2 * node];
		else
			M[node] = M[2 * node + 1]; 
	}
}

int query(int node, int b, int e, int i, int j){
	int p1, p2;

	//if the current interval doesn't intersect the query interval return -1
	if (i > e || j < b) return -1;

	//if the current interval is included in the query interval return M[node]
	if (b >= i && e <= j) return M[node];

	//compute the minimum position in the left and right part of the interval
	p1 = query(2 * node, b, (b + e) / 2, i, j);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);

	//return the position where the overall minimum is
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	if (A[p1] <= A[p2]) return p1;
	return p2;
}


int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	//Preprocessing - make segment tree
	initialize(1,0,N-1);

	//Queries
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int L, R;	//zero indexed
		scanf("%d %d", &L, &R);
		printf("%d\n", A[query(1, 0, N-1, L, R)]);
	}
	return 0;
}

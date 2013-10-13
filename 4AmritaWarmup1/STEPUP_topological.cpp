#include<stdio.h>
#include<vector>

using namespace std;

int cnt[10000];
vector <int> G[10000];
vector <int> V;
int col[10000];

int main() {
	int i,j,t,T,N,M,a,b,mx;
	scanf("%d", &T);
	for(t=0;t<T;t++){
		scanf("%d%d",&N,&M);
		for(i=0;i<N;i++){cnt[i]=0;G[i].clear();}
		for(i=0;i<M;i++) {
			scanf("%d%d",&a,&b);
			a--;b--;
			G[a].push_back(b);
			cnt[b]++;
		}
		V.clear();
		for(i=0;i<N;i++) if(cnt[i]==0) V.push_back(i);
		for(i=0;i<V.size();i++) {
			for(j=0;j<G[ V[i] ].size();j++) {
				cnt[ G[ V[i] ][j] ]--;
				if(cnt[ G[ V[i] ][j] ] == 0) V.push_back( G[ V[i] ][j] );
			}
		}
		if(V.size() != N) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		for(i=N-1;i>=0;i--) {
			mx = 0;
			for(j=0;j<G[ V[i] ].size();j++) {
				if( mx < col[ G[ V[i] ][j] ] ) mx = col[ G[ V[i] ][j] ];
			}
			col[ V[i] ] = mx+1;
		}
		mx = 0;
		for(i=0;i<N;i++) if(mx < col[i]) mx = col[i];
		printf("%d\n",mx);
	}
	return 0;	
}

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <stack>
#include <list>

using namespace std;

int main(){
	int job_num;
	scanf("%d", &job_num);

	vector<int> ad_list[job_num+1];
	list<int> job_order;

	//Make Ad_list
	char order[10];
	while(scanf("%s", order) != EOF){
		char first_job[10];
		int br;
		for (int i = 0; i < strlen(order); i++){
			if (order[i] == '<'){
				br = i;
				break;
			}
			first_job[i] = order[i];
		}
		first_job[br] = '\0';
		int job1 = atoi(first_job);
		int job2 = atoi(order+br+1);

		ad_list[job1].push_back(job2); 
	}


	//Apply Topological Sort
	//Apply DFS to compute finishing times and add in front of list
	bool visit[job_num+1];
	memset(visit, false, sizeof(visit));

	stack<int> s;

	vector<int>::iterator it[job_num+1];
	for (int i = 1; i <= job_num; i++){
		it[i] = ad_list[i].begin();
	}

	for (int i = 1; i <= job_num; i++){
		if (!visit[i]){
			s.push(i);
			visit[i] = true;

			while(!s.empty())
			{
				int w = s.top();


				for( ;it[w] != ad_list[w].end(); it[w]++)
				{
					int v = *(it[w]);
					if (!visit[v]){
						s.push(v);
						visit[v] = true;
						break;
					}
				}


				if (it[w] == ad_list[w].end()){
					s.pop();
					job_order.push_front(w);
				}
			}
		}
	}


	list<int>::iterator it_list;
	for(it_list = job_order.begin(); it_list != job_order.end(); it_list++ )
	{
		cout << *it_list << " ";
	}
}	

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

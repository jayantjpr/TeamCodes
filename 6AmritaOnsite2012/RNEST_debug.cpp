#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define MAX 100010
#define pp pair<int, int>

using namespace std;

pp start[MAX];
pp end[MAX];
vector< pair< pp, int> > q;

bool rectContain(int a, int b){
	if (a == -1)
		return true;
	if (start[a].first > start[b].first && 
			start[a].second < start[b].second &&
			end[a].first < end[b].first && 
			end[a].second > end[b].second) return true;
	else return false;
}

bool fncomp (pair< pp, int> lhs, pair< pp, int> rhs) {return lhs.first > rhs.first;}

int main(){
	int N;
	scanf("%d", &N);

	q.clear();
	for (int i = 0; i < N; i++){
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		start[i] = make_pair(y2, x1);
		end[i] = make_pair(y1, x2);
		q.push_back(make_pair(start[i], i));
		q.push_back(make_pair(end[i], i));
	}
	sort(q.begin(), q.end(), fncomp);
	
	vector<int> parent(N, -1); 
	set< pp > status;
	status.insert(make_pair(-1, -1));
	for( vector< pair< pp, int> >::iterator i = q.begin(); i != q.end(); i++){
		pp segPt = i -> first;
		int rectNum = i -> second;

		cout << "(" << segPt.first << "," << segPt.second << ")" << rectNum << endl;
		
		pp rectStartPt = make_pair(start[rectNum].second, rectNum);
		if (status.find(rectStartPt) != status.end()){
			cout << "delete " << rectNum << endl;
			status.erase(rectStartPt);
		}
		else{
			cout << "insert " << rectNum << ":"; 
			pp rectPt = make_pair(segPt.second, rectNum);
			set< pp >::iterator it = status.insert(rectPt).first;
			it--;
			if (rectContain(it -> second, rectNum)) parent[rectNum] = it -> second;
			else parent[rectNum] = parent[it->second];

			cout << "parent=" << parent[rectNum] << endl;
			
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", parent[i]);
}


#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

#define MAX 10010

using namespace std;

typedef long long ll;

int N;
ll a[MAX], sum[MAX];

inline bool checkPolygon(int k){
	for (int i = 1; i <= N-k; i++){
		ll sSum = sum[i+k-1]-sum[i-1];
		if (a[i+k] < sSum)
			return true;
	}
	return false;
}

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		memset(sum, 0, sizeof(sum));
		scanf("%d",&N);
		for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);
		sort(a+1, a+N+1);
		for (int i = 1; i <= N; i++) sum[i] = sum[i-1]+a[i];
		
		int end = N, start = 2, mid = (start+end+1)/2;
		while(start < end){
			//cout << start << " " << end << " " << mid << ":" << endl;
			if (checkPolygon(mid-1))
				start = mid;
			else
				end = mid-1;
			mid = (start+end+1)/2;
		}
		if (start < 3) printf("-1\n");
		else printf("%d\n", start);	
	}
	return 0;
}

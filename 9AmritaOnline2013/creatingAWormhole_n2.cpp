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

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		memset(sum, 0, sizeof(sum));
		scanf("%d",&N);
		for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);
		sort(a+1, a+N+1);
		for (int i = 1; i <= N; i++) sum[i] = sum[i-1]+a[i];
		
		bool found  = false;
		int val = -1;
		for (int j = N; j >= 3 && !found; j--){
			int k = j-1;
			for (int i = 1; i <= N-k && !found; i++){
				ll sSum = sum[i+k-1]-sum[i-1];
				if (a[i+k] < sSum)
					found = true, val = j; 
			}
		}

		if (!found) printf("-1\n");
		else printf("%d\n", val);	
	}
	return 0;
}

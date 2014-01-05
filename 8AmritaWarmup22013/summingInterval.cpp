#include <cstdio>

#define MAX 100010

typedef long long ll;

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int N, Q, a[MAX];
		scanf("%d %d", &N, &Q);

		ll sum[MAX] = {};
		for (int i = 1; i <= N; i++){
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}

		while(Q--){
			int L, R;
			scanf("%d %d", &L, &R);
			printf("%lld\n", sum[R+1]-sum[L]);		
		}
	}
	return 0;
}

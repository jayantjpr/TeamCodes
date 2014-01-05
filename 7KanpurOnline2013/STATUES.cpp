#include <cstdio>
#include <algorithm>

#define MAX 100

using namespace std;

int main(){
	int N, a[MAX], count = 1;;
	scanf("%d", &N);

	while(N != 0){
		int sum = 0;
		for (int i = 0; i < N; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sum /= N;
		int ans = 0;
		for (int i = 0; i < N; i++)
			ans += max(0, a[i]- sum);

		printf("Set #%d\n", count);
		printf("The minimum number of moves is %d.\n", ans);
		count++;
		scanf("%d", &N);
	}
	return 0;
}

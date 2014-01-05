#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

#define MAX 100000

using namespace std;

typedef long long ll;

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int N, a[MAX];
		scanf("%d", &N);

		for (int i = 0; i < N; i++) scanf("%d", &a[i]);
		printf("%d", N);
	}

	return 0;
}

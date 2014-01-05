#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>
#include <bitset>

#define MAX 110

using namespace std;

typedef long long ll;

int main(){
	int bit_vector[11];
	bit_vector[0] = 1;
	for (int i = 1; i <= 10; i++) bit_vector[i] = bit_vector[i-1] << 1;
	
	int N;
        ll a[MAX];
	while( scanf("%d", &N) != EOF){
		for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);

		ll mat[11][1025] = {};
		ll max_val = INT_MIN, max_card = INT_MIN;
		for (int i = 1; i <= N; i++){
			int di = 0;
			ll n = a[i];
			while(n != 0){
				int digit = n%10;
				n/=10;
				di |= bit_vector[digit];
			}

			for (int j = min(i, 10); j >= 1; j--){
				for (int d = 1024; d >= 0; d--){
					if (!(~d & di) && (mat[j-1][d-di] || j == 1)){ 
						mat[j][d] = max(mat[j-1][d-di]+a[i], mat[j][d]);
						if (mat[j][d] > max_val) max_val = mat[j][d], max_card = j;
						else if (mat[j][d] == max_val && j > max_card) max_card = j;
					}
				}
			}
		}
		printf("%lld\n", max_card);
	}

	return 0;
}

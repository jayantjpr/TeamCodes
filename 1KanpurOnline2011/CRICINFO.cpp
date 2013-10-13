#include <stdio.h>
#include <cstring>
using namespace std;

#define MOD 10000007
#pragma warning (disable: 4996)
typedef long long ulli;

const int R[] = {0,1,2,3,4,6,1,2,3,5,1,2,5,7,0};
const int W[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
const int B[] = {1,1,1,1,1,1,0,0,0,0,0,0,0,0,1};
long long data[10000][10][6];

ulli findCount(long r, int w, int b) {
	printf("%ld %d %d \n",r,w,b);
	if(r <= 0 || w == 0 || b == 0) return 1;
	if(data[r][w][b] != -1) return data[r][w][b];

	else {
		ulli count = 0;
		for (int i=0; i<15; i++)
			count = (count + findCount(r-R[i],w-W[i],b-B[i])) % MOD;

		count %= MOD;
		data[r][w][b] = count;
		return count;
	}
}

int main(int argc, char const *argv[]) {
	ulli t, count;
	long n; 

	scanf ("%llu",&t);
	for(ulli i = 1; i <= t ; i++) {
		memset(data,-1,sizeof(data));	
		scanf ("%ld",&n);
		count = 0;
		for (int j = 1; j<=10; ++j)
			count = (count + findCount(n,j,6)) % MOD;

		printf("Case %llu: %llu\n",i,count % MOD);
	}
//	scanf ("%llu",&t);
	return 0;
}
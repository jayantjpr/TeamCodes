#include <cstdio>

#define MAX 50
#define STR "zyxwvutsrqponmlkjihgfedcba"

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int K;
		scanf("%d", &K);

		int times = K/25;
		int left = K%25;

		char final[MAX] = {};
		
		if (left > 0){
			for(int i = 0; i <= left; i++) final[i] = 'a'+left-i;
			printf("%s", final);
		}
		for(int i = 0; i < times; i++)
			printf("%s", STR);
		printf("\n");
	}
	return 0;
}

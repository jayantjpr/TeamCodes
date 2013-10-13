#include <cstdio>
#include <cstring>

#define MAX 100

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		char S[MAX];
		scanf("%s", S);

		int len = strlen(S);
		bool zero = false, one = false;
		for (int i = 0; i < len; i++)
			if(S[i] == '0') zero = true;
			else if (S[i] == '1') one = true;

		if (zero && one) printf("2\n");
		else printf("1\n");
	}

	return 0;
}

#include<iostream>
#include<cstdio>

#define MOD 1000000007

using namespace std;

unsigned modPow(unsigned long long num, unsigned exp){
	unsigned long long result = 1;
	while(exp > 0){
		if (exp & 1)
			result = (result * num) % MOD;
		num = (num * num) % MOD;
		exp = exp >> 1;
	}

	return (unsigned(result%MOD));
}

/*unsigned int modInverse(unsigned b){
	long long y = 1, lasty = 0, temp;
	unsigned a = MOD;
	
	while (b != 0){
		unsigned quotient = a/b;
		unsigned remainder = a%b;
		a = b;
		b = remainder; 

		temp = lasty - (quotient*y);
	       	lasty = y;
		y = temp;
	}

	unsigned ans = (lasty + MOD)%MOD;

	return ans;
}*/

unsigned modInverse(unsigned a){
	return modPow(a, MOD-2);
}


int main()
{
	unsigned T, N;
	scanf("%d", &T);

	unsigned long long fact[1001];
	fact[0] = 1;
	for (unsigned i=1; i<=1000; i++)
		fact[i] = (fact[i-1] * i)%MOD;

	while(T--){
		scanf("%d", &N);
		
		char *line;
		size_t len = 0;
		getline(&line,&len,stdin);
		getline(&line,&len,stdin);
		
		unsigned ans = modPow(2,N-1);
		if (!(N&1)){
			unsigned nCnby2 = (((fact[N]*modInverse((fact[N/2]*fact[N/2])%MOD))%MOD)*modInverse(2))%MOD;
			ans = (ans - nCnby2 + MOD)%MOD;
		}

		printf("%u\n", ans);
	}

	return 0;
}
#include <cstdio>
#include <cstring>

#define MOD 1000000007
#define MAX 100010

char str[MAX];
unsigned long long fact[MAX/2];

unsigned long long modInverse(unsigned long long a){
	long long b = MOD, t, q;
	long long x0 = 0, x1 = 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	while(x1 < 0) x1 += MOD;
	return x1 % MOD;
}

int main(){
	scanf("%s", str);
	
	int len = strlen(str)/2;
	fact[0] = 1;
	for (int i = 1; i <= len; i++) fact[i] = (fact[i-1]*i) % MOD;

	char *ptr = str;
	int count[26] = {};
	while(*ptr != '\0') count[*ptr++ - 'a']++;
	
	unsigned long long anagrams = 1;
	for (int i = 0; i < 26; i++) count[i] >>= 1, anagrams = (anagrams * fact[count[i]]) % MOD;
	anagrams = (modInverse(anagrams) * fact[len]) % MOD;
	printf("%llu", anagrams);
	
	return 0;	
}

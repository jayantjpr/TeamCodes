/*#include <iostream>
#include <algorithm>
#include <iterator>*/
#include <cstdio>
#include <cstring>
#include <vector>


#define CHANGE "change"
#define QUERY "query"
#define MOD 3046201
#define MAX_BERRIES 30
#define MAX_FACT 3000000

using namespace std;

int fact[MAX_FACT];

int modExponent(unsigned long long base, unsigned exponent){
	unsigned long long result = 1;
	while(exponent > 0){
		if (exponent & 1)
			result = (result * base) % MOD;
		exponent >>= 1;
		base = (base * base) % MOD;
	}

	return (int)result;
}

int modMultiplicativeInverse(int a){
	return modExponent(a, MOD-2);
}

int modDistribute(int n, int k){
	unsigned q = n / k;
	unsigned r = n % k;
	unsigned long long ans = ((unsigned long long)fact[n] * fact[k])%MOD;
	unsigned long long denominator = ( (( (((unsigned long long)modExponent(fact[q+1], r) * modExponent(fact[q], k-r))%MOD) * fact[r])%MOD) * fact[k-r])%MOD;
	ans =  (ans * modMultiplicativeInverse((int)denominator))%MOD;

	return (int)ans;	
}


class BIT{
	vector<int> tree;

	public:

	BIT(int n){
		tree.clear();
		tree.resize(n+1,0);
	}

	int read(int idx){
		int sum = tree[idx];
		if (idx > 0){
			int z = idx - (idx & -idx);
			idx--;
			while(idx != z){
				sum -= tree[idx];
				idx -= (idx & -idx);
			}
		}
		return sum;
	} 
	
	int cummulate(int idx){
		int sum = 0;
		while(idx > 0){
			sum += tree[idx];
			idx -= (idx & -idx); 
		}
		return sum;
	}

	int cummulate(int from, int to){
		return cummulate(to) - cummulate(from-1);
	}
	
	void add(int idx, int val){
		while(idx <= (int)tree.size()-1){
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	
	void change(int idx, int val){
		int x = read(idx);
		int add_val = val - x;
		add(idx, add_val);
	}

	/*void print(){
		copy(tree.begin(), tree.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}*/
};

int main(){
	int N;
	scanf("%d", &N);
	
	//Precomputing factorials
	fact[0] = 1;
	unsigned long long max_berries = N*MAX_BERRIES;
	for (unsigned long long i = 1 ;  i < max_berries; i++){
		fact[i] = (int)((i * fact[i-1])%MOD);
	}

	//Constructing BIT
	BIT bit(N);
	for (int i = 1; i <= N; i++){
		int berries;
		scanf("%d", &berries);
		bit.add(i,berries);
	}

	int Q;
	scanf("%d", &Q);
	while(Q--){
		char type[10];
		int A, B;
		scanf("%s %d %d", type, &A, &B);
		
		if (strcmp(type, CHANGE) == 0)
			bit.change(A, B);
		else
			printf("%d\n", modDistribute(bit.cummulate(A,B), B-A+1));
	}
}

#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	while(b != 0){
		ll t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	while(a != 1 || b != 1){
		while(a != 1){
			ll next_frac = ceil((double)b/a);
			a = a*next_frac - b;
			b = b*next_frac;
			ll t = gcd(a, b);
			a /= t;
			b /= t;
			printf("%lld ", next_frac);
		}
		printf("%lld\n", b);
		scanf("%lld %lld", &a, &b);
	}
	return 0;

}

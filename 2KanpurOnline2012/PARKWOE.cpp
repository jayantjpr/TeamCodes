#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <cmath>
#include <climits>
#include <string>

#pragma warning (disable:4996)

using namespace std;
typedef long long ll;
const ll empty=2147483647;

#define NMAX 101
ll park[NMAX+1][NMAX+1];

int main () {
	int t,m,n;
	scanf ("%d\n", &t);
	
	while (t--) {
		scanf ("%d %d\n", &m, &n);
		memset(park, 0, sizeof park);

		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++) {
				scanf ("%lld", &park[i][j]);
			}
		
		int moves=0, x=0,y=0;
		while (park[x+1][y] != empty || park[x][y+1] != empty) {
			if (y==n-1) { while (x<m && park[x++][y] != empty) moves++; moves--; break; }
			if (x==m-1) { while (y<n && park[x][y++] != empty) moves++; moves--; break; }

			if (park[x+1][y] == empty) y++;
			else if (park[x][y+1] == empty) x++;
			else if (park[x][y+1] < park[x+1][y]) y++;
			else x++;
			
			moves++;
		}
		if (moves==0) printf ("%d\n", moves);
		else printf ("%d\n", moves);
	}
	
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string rev(string str) {
	reverse(str.begin(), str.end());
	return str;
}

int main () {
	string s;
	int t;
	cin >> t;

	while (t--) {
		cin >> s;
		if (s == rev(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
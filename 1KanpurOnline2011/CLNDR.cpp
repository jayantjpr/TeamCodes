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

//#pragma warning (disable: 4996)

typedef long long ll;
using namespace std;

const string Months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
const int Days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool isLeap (int y) {
	return (y%400 == 0) || ((y%4==0) && (y%100 != 0));
}

// TODO HANDLE NUMBERS like 01, 02,
// Convert string to T
// No error checking
template<typename T>
T stringToT (string s) {
	if(s == "") return 0;
	stringstream st(s);
	T x;
	
	st >> x;
	return x;
}

int main () {
	map<string, int> mapMonthsDate;
	int daysBefore[12]; daysBefore[0] =0;
	for (int i=1; i<12; i++) daysBefore[i] = daysBefore[i-1] + Days[i-1];
	for (int i=0; i<12; i++) mapMonthsDate[Months[i]] = daysBefore[i];

	int t,s, year, date;
	string month;
	char d[20];
	scanf ("%d", &t);
	s = t;
	while (t--) {
		scanf ("%s", &d);
		string dates = d;
		date = stringToT<int> (dates.substr (0,2));
		month = dates.substr (3, 3);
		year = stringToT<int> (dates.substr (7, 4));

		int totalDays = date;
		totalDays += mapMonthsDate[month];
		if (isLeap (year) && mapMonthsDate[month]>mapMonthsDate["FEB"])
			totalDays++;

		printf ("Case %d: ", s-t);
		if (totalDays<=300)
			printf ("%d Hundreds\n", totalDays);
		else {
			totalDays -= 300;
			if (totalDays <= 60)
				printf ("%d Tens\n", totalDays);
			else printf ("%d Ones\n", totalDays-60);
		}
	}

	return 0;
}
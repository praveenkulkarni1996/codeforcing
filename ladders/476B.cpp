// AC
#include <bits/stdc++.h>
using namespace std;

int C(int n, int r) {
	assert(r <= n);
	long long nr = 1, dr = 1;
	while(r > 0) {
		nr *= n--;
		dr *= r--;
	}
	return nr / dr;
}


int main() {
	string a, b;
	cin >> a >> b;
	int n = a.length();
	int pos1 = 0, pos2 = 0, num = 0;

	for(char ch: a) {
		if(ch == '+') pos1++;
		if(ch == '-') pos1--;
	}
	for(char ch: b) {
		if(ch == '+') pos2++;
		if(ch == '-') pos2--;
		if(ch == '?') num++;
	}

	int diff = max(pos2 - pos1, pos1 - pos2);

	if(diff > num) {
		cout << 0 << endl;
		return 0;
	}
	if((num - diff) % 2) {
		cout << 0 << endl;
		return 0;
	}
	int need = diff + (num - diff) / 2;

	cout << setprecision(10) << fixed << (long double)(C(num, need)) / (long double)(1LL << num) << endl;
}


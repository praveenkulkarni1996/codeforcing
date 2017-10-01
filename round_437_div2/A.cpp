#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int a = 0, b = 0;
	char prev = s[0];
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == prev) continue;
		if(s[i] == 'F') a++;
		if(s[i] == 'S') b++;
		prev = s[i];
	}
	cout << ((a > b) ? "YES" : "NO") << endl;

}

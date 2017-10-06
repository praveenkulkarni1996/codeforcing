#include <bits/stdc++.h>
using namespace std;

int main() {
	int c; cin >> c;
	int mx = 0;
	while(c--) {
		int x; cin >> x; mx = max(mx, x);
	}
	cout << max(mx - 25, 0) << endl;
}

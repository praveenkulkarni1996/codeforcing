#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int c = (int)ceil(sqrt(n));
	int f = (int)floor(sqrt(n));
	int p = (c * f < n) ? 4 * c : 2 * (c+f);
	cout << p << endl;
}

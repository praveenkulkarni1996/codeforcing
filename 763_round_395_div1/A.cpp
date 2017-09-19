#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int color[N+1];
pair<int, int> e[N];

int main() {
	int n; cin >> n;
	for(int i = 0; i < n-1; ++i) {
		cin >> e[i].first >> e[i].second;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> color[i];
	}
	int A = -1, B = -1;
	for(int i = 0; i < n-1; ++i) {
		int a = e[i].first;
		int b = e[i].second;
		if(color[a] != color[b]) {
			if(A == -1) {
				A = a; B = b;
			} else if(A == a || A == b || B == a || B == b) {
				A = (A == a || A == b) ? A : B;
			} else {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n" << ((A == -1) ? e[0].first : A) << endl;
}

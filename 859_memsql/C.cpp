#include <bits/stdc++.h>
using namespace std;


const int N = 50;
int dp[N + 10];
int a[N + 10];
int suff[N + 10];

int main() {
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	memset(suff, 0, sizeof(suff));

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = n; i >= 1; --i) {
		suff[i] = suff[i + 1] + a[i];
	}
	for(int i = n; i >= 1; --i) {
		dp[i] = max(dp[i+1], a[i] + suff[i+1] - dp[i+1]);
	}
	cout << suff[1] - dp[1] << " " << dp[1] << endl;
}

// AC out of contest. Code inspired by tourist.
#include <bits/stdc++.h>
using namespace std;

const int N = 51;
const int T = 10000 + 50;
const long double eps = 1e-9;

vector<int> fast, slow;
vector<long double> p;
long double dp[N][T];
int n, r;

long double pred(long double expect) {
	// assume that expect value is given to you.
	// when you fail, then you will reset and go back.
	// dp[n][t] is the expected time to finish after completing level n and
	// having already spent time t from the start (i.e r - t time remaining).
	int stot = 0;
	for(int i = 0; i < n; ++i) { stot += slow[i]; }

	for(int l = n; l >= 0; --l) {
		for(int t = 0; t <= stot; t++) {
			if(l == n) {
				dp[l][t] = (t > r) ? expect : 0;
				continue;
			}
			if(t + slow[l] > stot) continue;
			dp[l][t] = p[l] * (fast[l] + dp[l+1][t + fast[l]]) + (1 - p[l]) * (slow[l] + dp[l+1][t + slow[l]]);
			if(l > 0) {
				dp[l][t] = min(dp[l][t], expect);
			}
		}
	}
	// the actual expected time is dp[0][0]. We want both of them to be the
	// same. The real answer of `expect` will be between expect and dp[0][0].
	return (dp[0][0] > expect);
}

int main() {
	cin >> n >> r;
	fast.resize(n);
	slow.resize(n);
	p.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> fast[i] >> slow[i] >> p[i];
		p[i] /= 100.0;
	}
	long double lo = 0.0, hi = 1e15;;
	for(int i = 0; i < 120; ++i) {
		long double mid = (lo + hi) * 0.5;
		if(pred(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << setprecision(10) << fixed << lo << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
long long p[N][5];

inline long long dot(const int a, const int b) {
	long long dp = 0;
	for(int i = 0; i < 5; ++i) 
		dp += p[a][i] * p[b][i];
	return dp;
}

inline bool good(const int a, const int x, const int y) {
	long long cossign = (dot(x, y) + dot(a, a) - dot(x, a) - dot(y, a));
	return cossign <= 0;
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; ++i) 
		for(int j=0; j < 5; ++j)
		cin >> p[i][j];

	stack<int> q;
	for(int i = 0; i < n; ++i) {
		q.push(i);
	}
	while(q.size() > 2) {
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		int c = q.top(); q.pop();
		if(good(a, b, c)) q.push(a);
		if(good(b, a, c)) q.push(b);
		if(good(c, a, b)) q.push(c);
	}
	vector<int> answers;
	while(q.size() > 0) {
		bool is_good = true;
		int a = q.top(); q.pop();
		for(int i = 0; i < n; ++i) {
			if(i == a) continue;
			for(int j = 0; j < n; ++j) {
				if(j == a || j == i) continue;
				is_good = is_good and good(a, i, j);
			}
		}
		if(is_good) {
			answers.push_back(a);
		}
	}
	sort(answers.begin(), answers.end());
	cout << answers.size() << endl;
	for(int u: answers) {
		cout << u+1 << "\n";
	}
	return 0;
}

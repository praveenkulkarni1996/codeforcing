#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const long long MOD = 1e9 + 7;

vector<int> g[N];
bool occ[N];
bool mark[N];

int tree_dfs(int u) {
	mark[u] = true;
	int sz = 1;
	for(int v: g[u]) {
		assert(not mark[v]);
		sz += tree_dfs(v);
	}
	return sz;
}

bool cycle_dfs(int u, set<int> &hist) {
	bool cycle = false;
	mark[u] = true;
	hist.insert(u);
	for(int v: g[u]) {
		if(v == u) continue;
		else if(hist.count(v) == 1) {
			assert(mark[v]);
			cycle = true;
		} else if(not mark[v]) {
			cycle |= cycle_dfs(v, hist);
		}
	}
	hist.erase(hist.find(u));
	return cycle;
}


int main() {
	memset(occ, false, sizeof(occ));
	memset(mark, false, sizeof(mark));
	int n; cin >> n;

	for(int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		occ[a] = true;
		g[b].push_back(a);
	}

	long long ways = 1;
	for(int i = 0; i < N; ++i) {
		if(not occ[i] and g[i].size() > 0 and not mark[i]) {
			long long sz = tree_dfs(i);
			assert(mark[i]);
			ways = (ways * sz) % MOD;
		}
	}
	
	for(int i = 0; i < N; ++i) {
		if(not occ[i] and g[i].size() > 0) { 
			assert(mark[i]);
			continue;
		}
		if(occ[i] and g[i].size() > 0 and not mark[i]) {
			set<int> hist;
			if(cycle_dfs(i, hist)) { 
				ways = (2LL * ways) % MOD;
			}
		}
	}
	cout << ways << endl;
}

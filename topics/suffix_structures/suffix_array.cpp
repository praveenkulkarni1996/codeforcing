#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

const int nmax = 100000;
const int logmax = 20;

pair<pair<int, int>, int> asst[nmax];
int P[logmax][nmax];

const int lcp(int x, int y, int step, int n) {
  if(x == y) return n - x;
  int ret = 0;
  int limit = min(n - x, n - y);
  for(int k = step - 1; k >= 0 and (x < n and y < n); --k) {
    if(P[k][x] == P[k][y]) {
      x += 1 << k;
      y += 1 << k;
      ret += 1 << k;
      assert(ret <= limit);
    }
  }
  return ret;
}

int suffix_array(const string &s) {
  const int n = s.length();
  int jump = 0;
  int step;
  for(step = 0; jump / 2 < n; ++step) {
    for(int i = 0; i < n; ++i) {
      if(step == 0) {
        asst[i] = {{s[i] - 'a', s[i] - 'a'}, i};
      } else {
        int a = P[step - 1][i];
        int b = (i + jump < n) ? P[step - 1][i + jump] : -1;
        asst[i] = {{a, b}, i};
      }
    }
    sort(asst, asst + n);
    for(int i = 0; i < n; ++i) {
      if(i > 0 and asst[i].first == asst[i - 1].first) {
        P[step][asst[i].second] = P[step][asst[i - 1].second];
      } else {
        P[step][asst[i].second] = i;
      }
    }
    jump = (jump == 0) ? 1 : jump << 1;
  }
  return step;
}

int main() {
  string s; cin >> s;

  return 0;
}


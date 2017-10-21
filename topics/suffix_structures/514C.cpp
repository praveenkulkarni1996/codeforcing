// hashing
#include <iostream>
#include <set>
using namespace std;

const long long MOD = 100000004987; // is prime
const long long PRIME = 97;

long long prod(long long a, long long b) {
  return (MOD + ((a * b) % MOD)) % MOD;
}

long long add(long long a, long long b) {
  return (MOD + ((a + b) % MOD)) % MOD;
}

long long calchash(const string &s) {
  long long hash = 0;
  for(char ch: s) {
    hash = add((long long)ch, prod(PRIME, hash));
  }
  return hash;
}

set<pair<long long, int>> qset;

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    string s; cin >> s; 
    qset.insert({calchash(s), s.length()});
  }
  for(int i = 0; i < m; ++i) {
    string s; cin >> s;
    long long hashval = calchash(s);
    bool found = false;
    for(long long coeff = 1, j = s.length() - 1; j >= 0; --j, coeff = prod(coeff, PRIME)) {
      string test = "abc";
      for(char ch: test) { 
        if(ch != s[j]) {
          long long testval = add(hashval, prod(ch - s[j], coeff));
          if(qset.count({testval, s.length()})) {
            found = true;
          }
        }
      }
    }
    cout << (found ? "YES" : "NO") << "\n";
  }
}

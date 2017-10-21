#include <iostream>
#include <string> 
#include <vector>
using namespace std;

const int nmax = 1e5 + 10;
vector<int> pi;

void build_prefix(string &s) {
  int n = s.length() - 1;
  pi.resize(n + 1);
  pi[1] = 0;
  int k = 0;
  for(int q = 2; q <= n; ++q) {
    while(k > 0 and s[k + 1] != s[q]) {
      k = pi[k];
    }
    pi[q] = k = (s[k+1] == s[q] ? k+1 : k); 
  }
}

int main() {
  string s = (string)"$" + (string)"ababcaba";
  build_prefix(s);
  int n = s.length() - 1;
}

    


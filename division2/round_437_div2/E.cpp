#include <bits/stdc++.h>
using namespace std;

int main() {
	multiset<long long> buy, sold; 
	long long money = 0;

	int n;  cin >> n; 
	for(int i = 0; i < n; ++i) {
		long long x; cin >> x;

		int b = -1;
		if(not buy.empty() and *buy.begin() < x) {
			b = x - *buy.begin();
		}
		int s = -1;
		if(not sold.empty() and *sold.begin() < x) {
			s = x - *sold.begin();
		}
		if(s == -1 and b == -1) {
			buy.insert(x);
		} else if(s > b) {
			money += s;
			buy.insert(*sold.begin());
			sold.erase(sold.begin());
			sold.insert(x);
		} else {
			money += b;
			buy.erase(buy.begin());
			sold.insert(x);
		}
	}
	cout << money << endl;
}

#include <bits/stdc++.h>
using namespace std;

struct person {
	long long s, a, b;
};

bool cmp(const person &x, const person &y) {
	return (x.b - x.a) < (y.b - y.a);
}

vector<person> ps;

int main() {
	long long slice = 0;
	int n; cin >> n; 
	long long per_pizza; cin >> per_pizza;
	for(int i = 0; i < n; ++i) {
		long long ss, aa, bb; cin >> ss >> aa >> bb;
		ps.push_back({ss, aa, bb});
		slice += ss;
	}
	long long pizza = (slice + per_pizza - 1) / per_pizza;

	sort(ps.begin(), ps.end(), cmp);

	vector<person> aa, bb;

	long long a_slice = 0;
	for(int i = 0; i < ps.size(); ++i) {
		if(ps[i].a >= ps[i].b) { aa.push_back(ps[i]); a_slice += ps[i].s; }
	}
	long long b_slice = 0;
	for(int i = ps.size() - 1; i >= 0; --i) {
		if(ps[i].b > ps[i].a) { bb.push_back(ps[i]); b_slice += ps[i].s; }
	}

	queue<person> qa, qb;
	for(auto pa: aa) {
		qa.push(pa);
	}
	for(auto pb: bb) {
		qb.push(pb);
	}

	long long a_pizza = a_slice / per_pizza;
	long long b_pizza = b_slice / per_pizza;

	long long Aremaining = a_pizza * per_pizza;
	long long Bremaining = b_pizza * per_pizza;

	long long happyA = 0;
	while(Aremaining > 0) {
		assert(not qa.empty());
		if(qa.front().s <= Aremaining) {
			Aremaining -= qa.front().s;
			happyA += qa.front().s * qa.front().a;
			qa.pop();
		}
		else {
			happyA += qa.front().a * Aremaining;
			qa.front().s -= Aremaining;
			Aremaining = 0;
		}
	}

	long long happyB = 0;
	while(Bremaining > 0) {
		assert(not qb.empty());
		if(qb.front().s <= Bremaining) {
			Bremaining -= qb.front().s;
			happyB += qb.front().s * qb.front().b;
			qb.pop();
		} else {
			happyB += qb.front().b * Bremaining;
			qb.front().s -= Bremaining;
			Bremaining = 0;
		}
	}

	long long pizza_t = (a_slice + b_slice + per_pizza - 1) / per_pizza;
	if(a_pizza + b_pizza == pizza_t) {
		assert(qa.empty() and qb.empty());
		cout << happyA + happyB << endl;
		return 0;
	}
	if(a_pizza + b_pizza + 2 == pizza_t) {
		assert(not qa.empty() and not qb.empty());
		while(not qa.empty()) {
			happyA += qa.front().s * qa.front().a;
			qa.pop();
		}
		while(not qb.empty()) {
			happyB += qb.front().s * qb.front().b;
			qb.pop();
		}
		cout << happyA + happyB << endl;
		return 0;
	}
	long long extraA = 0, extraB = 0;
	while(not qa.empty()) {
		extraA += qa.front().s * qa.front().a;
		extraB += qa.front().s * qa.front().b;
		qa.pop();
	}
	while(not qb.empty()) {
		extraA += qb.front().s * qb.front().a;
		extraB += qb.front().s * qb.front().b;
		qb.pop();
	}
	cout << max(extraA, extraB) + happyA + happyB << endl;
}

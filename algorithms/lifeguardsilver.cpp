#include <bits/stdc++.h>

using namespace std;

struct Time {
	int l, r;
};

bool cmp (const Time& a, const Time& b) {
	return a.l < b.l;
}

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int n;
	cin >> n;
	vector<Time> ar(n);

	for (int i = 0; i < n; i++) {
		cin >> ar[i].l >> ar[i].r;
	}

	sort(ar.begin(), ar.end(), cmp); // sort lifeguards by start point
	int tot = 0, left = 0, right = 0;
	// tot = time that is covered if no lifeguards covered
	// right = max ending point of lifeguards considered so far

	for (int i = 0; i < n; i++) {
		if (ar[i].r > right) {
			left = max(right, ar[i].l);
			tot += ar[i].r - left;
			right = ar[i].r;
		}
	}

	int res = tot; // res = min time to subtract if one lifeguard removed
	Time last;
	last.l = ar[n - 1].r;
	ar.push_back(last);
	right = 0;
	for (int i = 0; i < n; i++) {
		int curRes = min(ar[i + 1].l, ar[i].r) - max(ar[i].l, right);
		res = min(res, curRes);
		right = max(right, ar[i].r);
	}

	res = max(res, 0); // if res < 0 then answer = tot
	cout << tot - res << '\n';
}
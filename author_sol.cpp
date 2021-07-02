#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		long long sum_a = 0;
		long long sum_b = 0;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			// check if their current speed (a[i] and b[i], ..., a[n - 1] and b[n - 1])
			// and their previous points (sum_a, sum_b) mathes with each other
			if (a[i] == b[i] && sum_a == sum_b) {
				res += a[i];
			}
			sum_a += a[i];
			sum_b += b[i];
		}
		cout << res << '\n';
	}
	return 0;
}

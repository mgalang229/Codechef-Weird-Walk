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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		// view the image in this repository for better understanding
		vector<long long> dp_a(n + 1);
		// set the initial distance of 'dp_a' (alice's distance) to 0
		dp_a[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			// then calculate the following points (x-coordinate) by getting the prefix sum with vector 'a'
			dp_a[i] = dp_a[i - 1] + a[i - 1];
		}
		vector<long long> dp_b(n + 1);
		// set the initial distance of 'dp_b' (bob's distance) to 0
		dp_b[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			// then calculate the following points (x-coordinate) by getting the prefix sum with vector 'b'
			dp_b[i] = dp_b[i - 1] + b[i - 1];
		}
		long long sum = 0;
		for (int i = 1; i < n + 1; i++) {
			// check if their current point and previous point matches
			if (dp_a[i] == dp_b[i] && dp_a[i - 1] == dp_b[i - 1]) {
				// if yes, then calculate the distance of the current point from the previous point and add it to sum
				sum += (dp_a[i] - dp_a[i - 1]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}

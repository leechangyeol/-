#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
const int MAX = 1001;
typedef long long ll;
ll A[MAX], B[MAX];
ll T;
int main(void) {
	cin >> T;
	cin >> n;
	vector<ll> V, V1;

	for (int i = 0; i < n; i++) 
		cin >> A[i];
	
	for (int i = 0; i < n; i++) {
		ll sum = A[i];
		V.push_back(sum);
		for (int j = i+1; j < n; j++) {
			V.push_back(sum += A[j]);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) 
		cin >> B[i];

	for (int i = 0; i < m; i++) {
		ll sum = B[i];
		V1.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			V1.push_back(sum += B[j]);
		}
	}

	sort(V.begin(), V.end());
	sort(V1.begin(), V1.end());
	ll ans = 0;
	for (auto temp : V) {
		int lb = lower_bound(V1.begin(), V1.end(), T - temp) - V1.end();
		int ub = upper_bound(V1.begin(), V1.end(), T - temp) - V1.end();
		ans += ub - lb;
	}
	cout << ans;
}

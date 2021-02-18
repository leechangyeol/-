#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 4000;
typedef long long ll;
vector<ll> value[4];
vector<ll> sum;
int n;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	value[0] = value[1] = value[2] = value[3] = vector<ll>(n);
	
	for (int i = 0; i < n; i++) {
		cin >> value[0][i] >> value[1][i] >> value[2][i] >> value[3][i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum.push_back(value[2][i] + value[3][j]);
		}
	}
	sort(sum.begin(), sum.end());

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll sub_sum = value[0][i] + value[1][j];
			ll left = lower_bound(sum.begin(), sum.end(), -sub_sum) - sum.begin();
			ll right = upper_bound(sum.begin(), sum.end(), -sub_sum) - sum.begin();
			if (sum[left] == -sub_sum)
				ans += right - left;
		}
	}
	cout << ans;
}

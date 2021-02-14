#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
const int MAX = 1000001;
ll list[MAX];
vector<ll> dp;
vector<ll> ans;
int index[MAX];
int lower_bound(ll target) {
	int start = 0, mid = 0, end = dp.size() - 1;
	while (start < end) {
		mid = (start + end) / 2;
		if (dp[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	dp[end] = target;
	return end+1;
}
int main(void) {
	cin >> n;
	cin >> list[0];
	dp.push_back(list[0]);
	index[0] = 1;
	for (int i = 1; i < n; i++) {
		cin >> list[i];
		if (list[i] > dp.back()) { 
			dp.push_back(list[i]); 
			index[i] = dp.size();
		}
		else { 
			int pos = lower_bound(list[i]);
			index[i] = pos;
		}
	}
	cout << dp.size() << "\n";
	int ans_idx = dp.size();
	for (int i = n-1; i >= 0; i--) {
		if (ans_idx == index[i]) {
			ans_idx--;
			ans.push_back(list[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto ans_next : ans)
		cout << ans_next << " ";
}


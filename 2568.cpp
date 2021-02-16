#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> value;
vector<int> dp;
int n;
const int MAX = 100001;
int index[MAX];
int _lower_bound(vector<int> &list, const int target) {
	int start = 0, mid = 0, end = list.size() - 1;
	while (start < end) {
		mid = (start + end) / 2;
		if (target <= list[mid])
			end = mid;
		else
			start = mid + 1;
	}
	list[end] = target;
	return end + 1;
}
int main(void) {
	cin >> n;
	int a,b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		value.push_back({ a,b });
	}
	sort(value.begin(), value.end());
	dp.push_back(value[0].second);
	index[0] = 1;
	for (int i = 1; i < n; i++) {
		if (dp.back() < value[i].second) {
			dp.push_back(value[i].second);
			index[i] = dp.size();
		}
		else {
			index[i] = _lower_bound(dp, value[i].second);
		}
	}
	int target_index = dp.size();
	vector<int> ans;
	for (int i = n-1; i >= 0; i--) {
		if (index[i] == target_index) {
			target_index--;
		}
		else {
			ans.push_back(value[i].first);
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end(), less<>());
	for (auto next : ans)
		cout << next << "\n";
}

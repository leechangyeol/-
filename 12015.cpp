#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
const int MAX = 1000000;
vector<int> dp;
int value[MAX];
void lower_bound(vector<int> &list, int target) {
	int mid, start = 0;
	int end = list.size() - 1;
	while (start < end) {
		mid = (start + end) / 2;
		if (list[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	list[end] = target;
}
int main(void) {
	cin >> n;
	cin >> value[0];
	dp.push_back(value[0]);
	for (int i = 1; i < n; i++) {
		cin >> value[i];
		if (value[i] > dp.back())
			dp.push_back(value[i]);
		else
		{
			lower_bound(dp, value[i]);
		}
	}
	cout << dp.size();
}

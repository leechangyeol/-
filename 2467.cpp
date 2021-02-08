#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<ll> list;
int main(void) {
	cin >> n;
	ll ans;
	for (int i = 0; i < n; i++) {
		cin >> ans;
		list.push_back(ans);
	}
	
	int low = 0, high = n - 1;
	ans = abs(list[low] + list[high]);
	int ans_low = low, ans_high = high;
	while (low + 1 < high && low < high -1) {
		if (abs(list[high]) > abs(list[low]))
			high--;
		else low++;

		if (ans > abs(list[low] + list[high])) {
			ans = abs(list[low] + list[high]);
			ans_low = low; ans_high = high;
			if (ans == 0)break;
		}
	}
	cout << list[ans_low] << " " << list[ans_high];
}

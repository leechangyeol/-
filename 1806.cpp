#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
const int MAX = 100000;
int map[MAX];
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> map[i];
	int high = 0, low = 0;
	int sum = map[0];
	int ans = MAX + 1;
	while (low <= high && high < n) {
		if (sum < m) {
			sum += map[++high];
		}
		else {
			ans = min(ans, high - low + 1);
			sum -= map[low++];
		}
	}
	if (ans == MAX + 1)cout << 0;
	else cout << ans;
}

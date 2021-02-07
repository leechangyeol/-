#include <iostream>
using namespace std;
const int MAX = 4000001;
bool prime[MAX];
int n;
int main(void) {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) {
			int temp = i * 2;
			while (temp <= n) {
				prime[temp] = 1;
				temp += i;
			}
		}
	}
	
	int low = 1, high = 1;
	int sum = 0, ans = 0;
	while (low <= n && high <= n) {
		if (sum < n) {
			while (prime[++high]);
			sum += high;
		}
		else if (sum == n) {
			ans++;
			while (prime[++low]);
			sum -= low;
		}
		else {
			while (prime[++low]);
			sum -= low;
		}
	}
	cout << ans;
}

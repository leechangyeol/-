#include <iostream>
using namespace std;
typedef long long ll;
int n, m;
const int MAX = 1001;
ll A[MAX],B[MAX],T;
int main(void) {
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	int al, ar, bl, br;
	al = ar = bl = br = 0;
	int ans = 0;
	ll a_sum = 0;
	while (ar <= n) {
		if (a_sum < T) {
			if (ar >= n) { ar++; break; }
			a_sum += A[ar++];
			ll b_sum = 0;
			br = bl = 0;
			while (br <= m) {
				if (a_sum + b_sum == T) {
					ans++;
					b_sum += B[br++];
				}
				else if (a_sum + b_sum < T)
					if (br < m)
						b_sum += B[br++];
					else br++;
				else b_sum -= B[bl++];
			}

		}
		else if (a_sum >= T) 
			a_sum -= A[al++];
	}
	cout << ans;
}

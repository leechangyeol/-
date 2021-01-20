#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 16;
int n;
int main(void) {
	int r, c;
	cin >> n >> r >> c;
	int x, y, ans;
	x = 0; y = 0; ans = 0;
	while (1) {
		x = 0; y = 0;
		for (int i = 0; i < n; i++) {
			if (c >= pow(2,i))
				x = i;
			if (r >= pow(2,i))
				y = i;
		}
		
		if (x > y) { // 2사
			ans += pow(2, x * 2);
			c -= pow(2, x);
		}
		else if (y > x) {
			ans += pow(2, y * 2) * 2;
			r -= pow(2, y);
		}
		else if (x == y && x != 0) {
			ans += pow(2, x * 2) * 3;
			r -= pow(2, x);
			c -= pow(2, x);
		}
		
		if (r <= 1 && c <= 1) {
			if (c == 1)ans += 1;
			if (r == 1)ans += 2;
			break;
		}
	}
	cout << ans << "\n";
}

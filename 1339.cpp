#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int ch[26];
int main(void) {
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		int idx = 0;
		for (int j = temp.size(); j >= 0; j--) {
			ch[temp[idx++] - 'A'] += pow(10, j-1);
		}
	}
	sort(ch, ch + 26,greater<int>());
	int ans = 0;
	int idx = 9;
	for (int i = 0; i < 26; i++) {
		if (!ch[i])break;
		ans += ch[i] * idx--;
	}
	cout << ans;
}

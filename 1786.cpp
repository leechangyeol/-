#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> fail(const string &p) {
	int n = p.size();
	int j = 0;
	vector<int> ans(n, 0);
	for (int i = 1; i < n; i++) {
		while (j > 0 && p[i] != p[j])
			j = ans[j - 1];
		if (p[i] == p[j]) {
			ans[i] = ++j;
		}
	}
	return ans;
}
vector<int> kmp(const string& s, const string& p) {
	int n = s.size();
	int m = p.size();
	int j = 0;
	vector<int> ans;
	auto f = fail(p);
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = f[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m-1) {
				ans.push_back(i - m + 1);
				j = f[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main(void) {
	string a, b;

	getline(cin, a);
	getline(cin, b);
	auto ans = kmp(a, b);
	cout << ans.size() << "\n";
	for (auto next : ans)
		cout << next + 1 << " ";
}

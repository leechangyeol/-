#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ans;
const int MAX = 100001;
vector<pair<int,int>> times;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		times.push_back({ b,a });
	}
	sort(times.begin(), times.end(), less<pair<int, int>>());
	int end, start;
	end = -1;
	for (auto next : times) {
		start = next.second;
		if (start >= end) {
			ans++; 
			end = next.first;
		}
	}
	cout << ans;
}

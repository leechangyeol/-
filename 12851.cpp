#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,int>> q;
int n, k, ans, cnt;
const int MAX = 100001;
bool visit[MAX];
int main(void) {
	cin >> n >> k;

	int temp, dist;
	ans = 9876543;
	q.push({n,0});
	while (!q.empty()) {
		temp = q.front().first;
		dist = q.front().second;
		q.pop();
		visit[temp] = 1;
		if (temp == k && ans > dist) {
			cnt = 1;
			ans = dist;
		}
		else if (temp == k && ans == dist)cnt++;
		
		if (ans < dist)continue;
		if (temp * 2 < MAX && !visit[temp * 2])
			q.push({ temp * 2,dist + 1 });
		if (temp + 1 < MAX && !visit[temp + 1])
			q.push({ temp +1,dist + 1 });
		if (temp - 1 >= 0 && !visit[temp - 1])
			q.push({ temp-1,dist + 1 });
	}

	cout << ans << "\n" << cnt;
}

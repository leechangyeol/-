#include <iostream>
#include <stack>
using namespace std;
const int MAX = 500001;
int n;
int V[MAX];
int ans[MAX];
stack<pair<int,int>> s;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}

	s.push({ V[0], 1 });
	ans[0] = 0;
	for (int i = 1; i < n; i++){
		while (!s.empty()) {
			if (s.top().first < V[i])
				s.pop();
			else if (s.top().first > V[i])
			{
				ans[i] = s.top().second;
				s.push({ V[i],i +1});
				break;
			}
		}
		if (s.empty()) {
			ans[i] = 0;
			s.push({ V[i],i+1});
		}
	}
	for (int i = 0;i<n;i++)
		cout << ans[i] << " "; 
}

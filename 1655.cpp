#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> mi_pq;
priority_queue<int> gr_pq;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (gr_pq.size() > mi_pq.size())
			mi_pq.push(temp);
		else gr_pq.push(temp);

		if (!mi_pq.empty())
		{
			if (gr_pq.top() > mi_pq.top())
			{
				int gr = gr_pq.top();
				int mi = mi_pq.top();
				gr_pq.pop(); mi_pq.pop();

				gr_pq.push(mi);
				mi_pq.push(gr);
			}
		}
		cout << gr_pq.top() << "\n";
	}
}

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500000
using namespace std;

int n, m;
vector<int> card;
vector<int> m_search;

int ans[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		card.push_back(temp);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		m_search.push_back(temp);
	}

	sort(card.begin(),card.end());

	for (int curCard = 0; curCard < m; curCard++)
	{
		int high = n-1;
		int mid = 0;
		int low = 0;
		int same = 0;

		while (low <= high)
		{
			mid = (high + low) / 2;
			if (card[mid] == m_search[curCard])
			{
				same = 1;
				break;
			}

			if (card[mid] > m_search[curCard])
				high = mid - 1;
			else low = mid + 1;
		}
		if (same)ans[curCard] = 1;
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << " ";
}

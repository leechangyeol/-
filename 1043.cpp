#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int parent[MAX];
vector<int> knowPeople;
vector<int> party[MAX];

int n, m;

int getParent(int p)
{
	if (p == parent[p]) return parent[p];
	else return parent[p] = getParent(parent[p]);
}

void joinParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	parent[a] = b;
}

int main(void)
{
	cin >> n >> m;

	int numberOfKnow;
	cin >> numberOfKnow;

	for (int i = 0; i < numberOfKnow; i++)
	{
		int a; cin >> a;
		knowPeople.push_back(a);
	}

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a; cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b; cin >> b;
			party[i].push_back(b);
		}

		a = party[i][0];
		for (int j = 1; j < party[i].size(); j++)
		{
			joinParent(a, party[i][j]);
		}
	}

	int ans = m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < knowPeople.size(); j++)
		{
			if (getParent(knowPeople[j]) == getParent(party[i][0]))
			{
				ans--; break;
			}
		}
	}

	cout << ans;
}

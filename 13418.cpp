#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

struct P { int a, b, c; };
vector<P> v;

int parent[MAX];
int n, m;

int getParent(int x)
{
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)return 1;
	else return 0;
}

int sol() {
	for (int i = 0; i <= n; i++)parent[i] = i;

	int cnt, ret;
	cnt = ret = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (!find(v[i].a, v[i].b))
		{
			unionParent(v[i].a, v[i].b);
			if (v[i].c == 0) ret++;
			if (++cnt == n)break;
		}
	}
	return ret * ret;
}
int main(void) 
{
	cin >> n >> m;

	for (int i = 0; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end(), [](P& u, P& v)->bool {return u.c < v.c; });
	int ans = sol();

	sort(v.begin(), v.end(), [](P& u, P& v)->bool {return u.c > v.c; });
	ans -= sol();
	cout << ans;
}

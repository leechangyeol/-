#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
string list;
string voelList = "aeiou";
void dfs(int index, int cnt, string ans)
{
	if (cnt == L)
	{
		int voel = 0;
		int nonVoel = 0;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < voelList.size(); j++)
			{
				if (ans[i] == voelList[j])
				{
					voel++;
					break;
				}
			}
			if (voel + nonVoel == i)
				nonVoel++;
		}
		if(voel >= 1 && nonVoel >= 2)
			cout << ans << "\n";
	}
	else
	{
		for (int i = index+1; i < list.size(); i++)
		{
			dfs(i, ans.size() + 1, ans + list[i]);
		}
	}
}
int main(void)
{
	cin >> L >> C;
	
	for (int i = 0; i < C; i++)
	{
		char temp;
		cin >> temp;
		list += temp;
	}

	sort(list.begin(), list.end());

	dfs(-1, 0, "");

}

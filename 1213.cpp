#include <iostream>
#include <algorithm>

using namespace std;

string name;
int main(void)
{
	cin >> name;

	sort(name.begin(), name.end());

	bool odd = false;
	
	string ans = "";
	string oddString = "";
	for (int i = name.size()-1; i >= 0; i--)
	{
		if (i-1 >= 0 && name[i] == name[i - 1] ) 
			ans = name[i] + ans + name[--i];
		else if (!odd)
		{
			odd = true;
			oddString = name[i];
		}
		else if (odd)
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}
	if (odd)
		ans.insert(ans.size() / 2, oddString);

	cout << ans;
	return 0;
}

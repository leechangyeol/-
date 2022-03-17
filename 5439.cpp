#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		string com;
		cin >> com;
		int n;
		cin >> n;

		vector<int> v;

		string number;
		cin >> number;


		for (int i = 0; i < number.size(); i++)
		{
			int temp = 0;
			if (48 <= (int)number[i] && (int)number[i] <= 57)
			{
				do 
				{
					temp = temp * 10 + ((int)number[i] - 48);
				} while (48 <= (int)number[++i] && (int)number[i] <= 57);
				v.push_back(temp);
			}
		}

		bool Rcom = false;
		bool error = false;
		for (int i = 0; i < com.size(); i++)
		{
			if (com[i] == 'R')
				Rcom = !Rcom;
			else 
			{
				if (v.empty())
				{
					cout << "error\n";
					error = true;
					break;
				}
				if (Rcom) v.erase(v.begin() + v.size() - 1);
				else v.erase(v.begin());
			}	
		}
		if (!error) 
		{
			cout << "[";
			
			if (v.size() > 0)
			{
				if (!Rcom)
				{
					cout << v[0];
					for (int i = 1; i < v.size(); i++)
					{
						cout << "," << v[i];
					}
				}
				else
				{
					cout << v[v.size()-1];
					for (int i = v.size()-2; i >= 0; i--)
					{
						cout << "," << v[i];
					}
				}
				
			}

			cout << "]\n";
		}
	}
	
}

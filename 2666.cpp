#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
const int MAX = 21;
int min_point = 987654321;
int pos1, pos2;
int checkList[MAX];

void dfs(int point,int cnt) {
	if (cnt == m) {
		min_point = min(point, min_point);
		return;
	}
	int temp = pos1;
	pos1 = checkList[cnt];
	dfs(point + (abs(checkList[cnt] - temp)), cnt + 1);
	pos1 = temp;
	temp = pos2;
	pos2 = checkList[cnt];
	dfs(point + (abs(checkList[cnt] - temp)), cnt + 1);
	pos2 = temp;
	return;
}
int main(void) {

	cin >> n;
	cin >> pos1 >> pos2;
	cin >> m;

	for(int i = 0;i<m;i++)
		cin >> checkList[i];
	dfs(0, 0);
	cout << min_point;
}

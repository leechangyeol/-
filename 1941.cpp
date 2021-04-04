#include <iostream>

using namespace std;

int map[5][5];
bool visited[5][5];

int main(void) {
	string temp;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		for (int j = 0; j < 5; j++) {
			if (temp[j] == 'Y')
				map[i][j] = 0;
			else map[i][j] = 1;
		}
	}



}

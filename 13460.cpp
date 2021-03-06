#include <iostream>
#include <queue>
using namespace std;
class pos {
public:
	int ry,rx,by,bx;
	int state; // 0 아무일 없음, 1 빨간공 탈출, 2 파란공 탈출
	int level;
};
int map[10][10];
int h, w;
queue <pos> q;
pos move(pos input, int dir) { //  0 위, 1 아래, 2 왼 , 3오 return 1 = 정답 return 2 = 파란색 아웃.
	input.state = 0;
	pos p = input;
	if (dir == 0) {
		if (p.ry <= p.by) {
			while (!map[p.ry-1][p.rx]) {p.ry--;}
			if (map[p.ry - 1][p.rx] == 2) {p.state = 1;}
			else { map[p.ry][p.rx] = 3; }
			while (!map[p.by - 1][p.bx]) {p.by--;}
			if (map[p.by - 1][p.bx] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;
		}
		if (p.ry > p.by) {
			while (!map[p.by - 1][p.bx]) { p.by--; }
			if (map[p.by - 1][p.bx] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;
			while (!map[p.ry - 1][p.rx]) { p.ry--; }
			if (map[p.ry - 1][p.rx] == 2) {p.state = 1;}
			map[p.ry][p.rx] = 3;
		}
	}
	else if (dir == 1) {
		if (p.ry >= p.by) {
			while (!map[p.ry + 1][p.rx]) { p.ry++; }
			if (map[p.ry + 1][p.rx] == 2) {p.state = 1;}
			else { map[p.ry][p.rx] = 3; }
			while (!map[p.by + 1][p.bx]) { p.by++; }
			if (map[p.by + 1][p.bx] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;
		}
		if (p.ry < p.by) {
			while (!map[p.by + 1][p.bx]) { p.by++; }
			if (map[p.by + 1][p.bx] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;
			while (!map[p.ry + 1][p.rx]) { p.ry++; }
			if (map[p.ry + 1][p.rx] == 2) {p.state = 1;}
			map[p.ry][p.rx] = 3;
		}
	}
	else if (dir == 2) {
		if (p.rx <= p.bx) {
			while (!map[p.ry][p.rx - 1]) { p.rx--; }
			if (map[p.ry][p.rx-1] == 2) {p.state = 1;}
			else { map[p.ry][p.rx] = 3; }
			while (!map[p.by][p.bx - 1]) { p.bx--; }
			if (map[p.by][p.bx-1] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;
		}
		if (p.rx > p.bx) {
			while (!map[p.by][p.bx - 1]) { p.bx--; }
			if (map[p.by][p.bx-1] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;
			while (!map[p.ry][p.rx-1]) { p.rx--; }
			if (map[p.ry][p.rx-1] == 2) {p.state = 1;}
			map[p.ry][p.rx] = 3;

		}
	}
	else if (dir == 3) {
		if (p.rx >= p.bx) {
			while (!map[p.ry][p.rx + 1]) { p.rx++; }
			if (map[p.ry][p.rx + 1] == 2) {p.state = 1;}
			else { map[p.ry][p.rx] = 3; }
			while (!map[p.by][p.bx + 1]) { p.bx++; }
			if (map[p.by][p.bx + 1] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;
		}
		if (p.rx < p.bx) {
			while (!map[p.by][p.bx + 1]) { p.bx++; }
			if (map[p.by][p.bx + 1] == 2) {p.state = 2;}
			map[p.by][p.bx] = 3;			
			while (!map[p.ry][p.rx + 1]) { p.rx++; }
			if (map[p.ry][p.rx + 1] == 2) {p.state = 1;}
			map[p.ry][p.rx] = 3;

		}
	}
	map[p.ry][p.rx] = 0;
	map[p.by][p.bx] = 0;
	if (p.bx == input.bx && p.by == input.bx && p.rx == input.rx && p.ry == input.rx) p.state = 2;
	return p;
}
pair<pair<int, int>, pair<int, int>> RB;
int main(void) {
	cin >> h >> w;
	string temp;
	pair<int, int> R;
	pair<int, int> B;
	pair<int, int> exit;

	for (int i = 0; i < h; i++) {
		cin >> temp;
		for (int j = 0; j < w; j++) {
			if (temp[j] == '#')
				map[i][j] = 1;
			else if (temp[j] == '.')
				map[i][j] = 0;
			else if (temp[j] == 'R') {
				R = { i, j };
			}
			else if (temp[j] == 'B') {
				B = { i, j };
			}
			else if (temp[j] == 'O') {
				exit = { i,j };
				map[i][j] = 2;
			}
		}
	}

	pos input = { R.first,R.second,B.first,B.second,0, 1};
	q.push(input);
	while (!q.empty()) {
		pos temp = q.front();
		q.pop();
		if (temp.level > 10)break;
		for (int i = 0; i < 4; i++) {
			pos next = move(temp, i);
			if (next.state == 1) {
				cout << next.level;
				return 0;
			}
			else if (next.state == 0) {
				next.level += 1;
				q.push(next);
			}
		}
	}
	cout << -1;
}

#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int MAX = 100;
int sp[MAX];
int main(void) {
	string input, ans;
	cin >> input;
	int splevel = 0;
	int temp = 0;
	stack<int> st;
	// 17 ~ 42
	while (temp < input.size()) {
		if (input[temp] - '0' >= 17 && input[temp] - '0' <= 42)
			ans.push_back(input[temp]);
		else {
			if (input[temp] == '(') {
				sp[++splevel] = st.size();
			}
			else if (input[temp] == ')') {
				while (sp[splevel] != st.size()) {
					ans.push_back(st.top());
					st.pop();
				}
				splevel--;
			}
			else if (input[temp] == '*' || input[temp] == '/') {
				while (sp[splevel] != st.size() && (st.top() == '*' || st.top() == '/')) {
					ans.push_back(st.top());
					st.pop();
				}
				st.push(input[temp]);
			}
			else { 
				while (sp[splevel] != st.size()) {
					ans.push_back(st.top());
					st.pop();
				}
				st.push(input[temp]);
			 }
		}
		temp++;
	}
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	cout << ans;
}

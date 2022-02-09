#include <iostream>

using namespace std;

#define MAX 5001

int A, K, N;
int arr[MAX];
int dp[MAX];
int ans = 0;
int abs(int a) { if (a < 0)return -a; else return a;}
int main(void)
{
	cin >> N >> K;


	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		if (dp[i] > 0) {
			for (int j = i; j < N; j++) {
				int power = (j - i) * (1 + abs(arr[i] - arr[j]));
				if (power <= K)dp[j]++;
			}
		}
	}
	
	if (dp[N - 1] == 0)
		cout << "NO";
	else cout << "YES";
}

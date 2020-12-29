#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000001
#define MOD 1000000007
using namespace std;
bool eratos[MAX];
int minFactor[MAX];
int n;
vector<int> prime;
int main(void) {
	cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);


	eratos[0] = eratos[1] = 1;
	for (int i = 2; i < MAX; i++) {
		minFactor[i] = i;
	}
	for (int i = 2; i*i < MAX; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j < MAX; j += i) {
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
	int mc = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a = b - a;
		while (1) {
			if (a == 1)break;
			prime.push_back(minFactor[a]);
			a /= minFactor[a];
		}
		while (1) {
			if (b == 1)break;
			prime.push_back(-minFactor[b]);
			b /= minFactor[b];
			mc++;
		}
	}
	sort(prime.begin(), prime.end());
	
	int dc,uc;
	dc = mc - 1;
	uc = mc;
	while (1) {
		if (dc < 0)break;
		if (uc >= prime.size())break;
		if (prime[uc] == -prime[dc]) {
			prime[uc] = 0;
			prime[dc] = 0;
			uc++; dc--;
		} 
		else if (prime[uc] > -prime[dc])dc--;
		else uc++;
	}
	long long upSum, downSum;
	upSum = downSum = 1;
	for (auto i : prime) {
		if (i < 0) {
			downSum *= -i;
			downSum %= MOD;
		}
		else if (i > 0) {
			upSum *= i;
			upSum %= MOD;
		}
	}
	cout << upSum << " " << downSum;

}

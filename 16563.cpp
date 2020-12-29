#include <iostream>
#include <vector>

#define MAX 5000001

using namespace std;
bool eratos[MAX];
int minFactor[MAX];
int n;

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

	cin >> n;

	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		while (1) {
			cout << minFactor[b] << " ";
			b /= minFactor[b];
			if (b == 1)break;
		}
		cout << "\n";
	}
	
}

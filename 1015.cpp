#include<iostream>
#include<algorithm>

using namespace std;

int B[50];
pair<int, int> A[50];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A, A + n);

    for (int i = 0; i < n; i++)
    {
        B[A[i].second] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }

    return 0;
}

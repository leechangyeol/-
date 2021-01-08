#include <iostream>
#define MOD 10007

using namespace std;
int n;
int dp[1001];

int sol(int x){
    if(x == 1)return 1;
    if(x == 2)return 2;
    if(dp[x] != 0)return dp[x];
    return dp[x] = (sol(x-1)+sol(x-2))%MOD;
}

int main(void){
        
    cin >> n;
    cout << sol(n);
}

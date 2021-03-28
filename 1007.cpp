#include<iostream>
#include<math.h>
using namespace std;

double ans;
int n, t;
int ax[21];
int ay[21];
bool c[21];
void combination(int cnt, int index) {
    if (cnt == n / 2) {
        double x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (c[i]) {
                x -= ax[i];
                y -= ay[i];
            }
            else {
                x += ax[i];
                y += ay[i];
            }
        }
        ans = min(ans, sqrt(x*x + y*y));
        return;
    }
    if (index == n) return;
 
    combination(cnt, index + 1);
    c[index] = true;
    combination(cnt + 1, index + 1);
    c[index] = false;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e3 + 3;

int main() {
    // m是最大装载量,n是集装箱数量,w[i]代表第i个集装箱的重量
    int m, n;
    int w[MAX];
    int dp[MAX];
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]]+1);
        }
    }
    cout << "The max box number is " << dp[m] << endl;
}

/*
输入
10 5
1 3 5 7 9
 */
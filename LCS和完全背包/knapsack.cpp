#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e3 + 3;

int w[MAX];
int v[MAX];
int dp[MAX];

int main() {
    // m为背包容量,n为物品个数
    int m, n;
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j=w[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << "Total weight is " << dp[m];
}

/*
输入
10 5
1 2
3 4
5 6
7 8
9 10
 */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAX = 1e3 + 3;

int dp[MAX][MAX];

void LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // 初始化第一行第一列
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    cout << "The LCS is " << dp[m][n] << endl;
}

void print(string X, string Y, int i, int j) {
    // 输出最长公共子序列
    if (i <= 0 || j <= 0) {
        return;
    }

    if (X[i-1] == Y[j-1]) {
        print(X, Y, i-1, j-1);
        cout << X[i-1];
    } else if (dp[i-1][j] > dp[i][j-1]) {
        print(X, Y, i-1, j);
    } else {
        print(X, Y, i, j-1);
    }
}

int main() {
    string X, Y;
    cin >> X >> Y;
    LCS(X, Y);
    print(X, Y, X.size(), Y.size());
}

/*
输入
ACDBC
CBCA
 */
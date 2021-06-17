#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1e3 + 3;

int f[MAX][MAX];
int F[MAX][MAX];
int m, n;

void invest() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                F[i][j] = max(F[i][j], f[i][k] + F[i-1][j-k]);
            }
        }
    }
    // 输出结果
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << F[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    scanf("%d %d", &m, &n);
    memset(f, 0, sizeof(f));
    memset(F, 0, sizeof(F));
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &f[j][i]);
        }
    }
    invest();
}

/**
输入
5 4
0 0 0 0 
11 0 2 20
12 5 10 21
13 10 30 22
14 15 32 23
15 20 40 24
 */
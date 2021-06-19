#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1e3 + 3;

int n;
int p[MAX];
int m[MAX][MAX];    // 区间状态值
int s[MAX][MAX];    // 区间分割点


void matrixChain() {
    // 矩阵链长度
    for (int len = 1; len <= n; len++) {
        // 区间左边
        for (int i = 1; i <= n-len; i++) {
            // 区间右端点
            int j = len + i;
            // 区间右边
            for (int k = i; k < j; k++) {
                // 通式
                int q = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(int left, int right) {
    // 输出括号化结果
    if (left == right) {
        cout << "A" << left;
    } else {
        cout << "(";
        print(left, s[left][right]);
        print(s[left][right]+1, right);
        cout << ")";
    }
}

int main() {
    memset(m, INF, sizeof(m));
    cin >> n;
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
        m[i][i] = 0;
    }
    matrixChain();
    cout << "The optimal solution is ";
    cout << m[1][n] << endl;
    cout << "Bracketing result is ";
    print(1, n);
}

/*
输入
4
10 24 4 5 99
 */
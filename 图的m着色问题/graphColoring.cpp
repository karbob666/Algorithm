#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e3 + 3;

int m;      // m种颜色
int n, e;   // n个顶点，e条边
int sum = 0;    // 所有可能的着色方案总数
int color[MAX]; // 存储各点的着色情况
int map[MAX][MAX];   // 各点之间的关系  1：两点连接 0：两点断开

bool check(int i) {
    // 判断当前点的着色是否合法合法
    for (int j = 1; j < i; j++) {
        // 两点如果相通并且与周围点的着色相同，就return false 表明当前的颜色选择不合法
        if (map[i][j] && color[i] == color[j]) {
            return false;
        }
    }
    return true;
}

void graphColoring(int i) {
    if (i > n) {
        sum++;
        for (int j = 1; j <= n; j++) {
            cout << color[j] << " ";
        }
        cout << endl;
        return;
    }
    for (int j = 1; j <= m; j++) {
        color[i] = j;
        if (check(i)) {
            graphColoring(i+1);
        }
        color[i] = 0;
    }
}

int main() {
    cout << "Please input the number of vertex and number of edge:";
    scanf("%d %d", &n, &e);
    memset(map, 0, sizeof(map));
    cout << "Please input the number of color:";
    scanf("%d", &m);
    for (int i = 1; i <= e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        map[u][v] = map[v][u] = 1;
    }
    graphColoring(1);
    cout << "The total project of color is " << sum << endl;
}

/*
输入
5 8
4
1 3
1 2
1 4
2 3
2 4
2 5
3 4
4 5
 */
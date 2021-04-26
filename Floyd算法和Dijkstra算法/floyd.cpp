#include <iostream>
#include <cstdio>
#include <cstring>

#define INPUT_PATH "input1.txt"

using namespace std;

const int MAX_SIZE = 1e3 + 3;   
const int INF = 0x3f3f3f3f;     // 无穷大

// 顶点个数和边个数
int vertexNumbers, edgeNumbers;
// dis[i][j]表示顶点i到顶点j的距离
int dis[MAX_SIZE][MAX_SIZE];

/**
 * @brief 读取数据, 初始化操作 
 */
void init() {
    int vertex1;
    int vertex2;
    int weight;
    scanf("%d %d", &vertexNumbers, &edgeNumbers);
    // 将所有距离都设置为无穷大
    memset(dis, INF, sizeof(dis));
    // 读取数据
    for (int i = 1; i <= vertexNumbers; i++) {
        scanf("%d %d %d", &vertex1, &vertex2, &weight);
        dis[vertex1][vertex2] = weight;
    }
}

void floyd() {
    // k表示i到j路径中存在i经过若干个顶点k再到j
    for (int k = 1; k <= vertexNumbers; k++) {
        for (int i = 1; i <= vertexNumbers; i++) {
            for (int j = 1; j <= vertexNumbers; j++) {
                // 如果从i到j的路径中, 存在i到k再到j比i到j的路径短, 则选择最短的那条路径
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

/**
 * @brief 输出最短距离矩阵
 */
void print() {
    for (int i = 1; i <= vertexNumbers; i++) {
        for (int j = 1; j <= vertexNumbers; j++) {
            cout << "\t" << dis[i][j];
        }
        cout << endl;
    }
}

int main() {
    freopen(INPUT_PATH, "r", stdin);
    init();
    floyd();
    print();
    fclose(stdin);
}
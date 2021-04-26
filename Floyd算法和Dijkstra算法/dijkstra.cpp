#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define INPUT_PATH "input2.txt"

using namespace std;

const int MAX_SIZE = 1e3 + 3;
const int INF = 0x3f3f3f3f;     // 无穷大
int vertexNumbers, edgeNumbers; // 顶点个数和边个数
int graph[MAX_SIZE][MAX_SIZE];  // 存储顶点的权重
int dis[MAX_SIZE];              // 存储源点到各个顶点间的距离
bool visited[MAX_SIZE];         // 判断顶点是否被访问过

/**
 * @brief 将字母a-z转化成数字0-25
 * 
 * @param value 
 * @return int 
 */
int charToInt(char value) {
    return value - 'a';
}

/**
 * @brief 将数字0-25转化成字母a-z
 * 
 * @param value 
 * @return char 
 */
char intToChar(int value) {
    return value + 'a';
}

void init() {
    char vertex1;
    char vertex2;
    int weight;
    // 初始化visited为false, dis和graph为无穷大
    memset(visited, false, sizeof(visited));
    memset(graph, INF, sizeof(graph));
    memset(dis, INF, sizeof(dis));
    scanf("%d %d\n", &vertexNumbers, &edgeNumbers);
    // 读取边和权重
    for (int i = 0; i < edgeNumbers; i++) {
        scanf("%c %c %d\n", &vertex1, &vertex2, &weight);
        graph[charToInt(vertex1)][charToInt(vertex2)] = weight;
    }
}

int dijkstra(int start, int end) {
    dis[start] = 0;
    visited[start] = true;
    // 初始化start到各个顶点的距离
    for (int i = 0; i < vertexNumbers; i++) {
        dis[i] = graph[start][i];
    }
    for (int i = 0; i < vertexNumbers-1; i++) {
        int minWeight = INF;
        int index;
        // 寻找距离最近的点
        for (int j = 0; j < vertexNumbers; j++) {
            if (!visited[j] && dis[j] < minWeight) {
                minWeight = dis[j];
                index = j;
            }
        }
        visited[index] = true;
        for (int j = 0; j < vertexNumbers; j++) {
            dis[j] = min(dis[j], dis[index] + graph[index][j]);
        }
    }
    return dis[end];
}


int main() {
    freopen(INPUT_PATH, "r", stdin);
    // 初始化, 读取数据
    init();
    char start, end;
    scanf("%c %c", &start, &end);
    // 计算从start到end的最短距离
    int minDistance = dijkstra(charToInt(start), charToInt(end));
    cout << "The distance is " << minDistance << endl;
    fclose(stdin);
}
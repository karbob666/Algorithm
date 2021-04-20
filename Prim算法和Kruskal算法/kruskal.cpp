#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define PATH "input.txt"

using namespace std;

const int MAX_SIZE = 1e3 + 3;
const int INF = 0x3f3f3f3f; // 无穷大
        
// 存储无向图的边
struct Node {
    int vertex1;
    int vertex2;
    int weight;

} graph[MAX_SIZE];
// 最小生成树
vector<Node> MST;
// vertexNumbers是总的顶点数, edgeNumbers总的边数
int vertexNumbers, edgeNumbers;

/**
 * @brief 比较器, 用于权重按照升序排序
 */
int comparator(const Node& edge1, const Node& edge2) {
    return edge1.weight < edge2.weight;
}

/**
 * @brief 寻找顶点vertex的父结点
 * 
 * @param parent 存储顶点的父结点数组
 * @param vertex 顶点
 * @return int 父结点
 */
int findParent(int parent[], int vertex) {
    return parent[vertex] == vertex ? 
           vertex : parent[vertex] = findParent(parent, parent[vertex]);
}

/**
 * @brief 建图
 */
void createGraph() {
    int vertex1, vertex2, weight;
    scanf("%d %d", &vertexNumbers, &edgeNumbers);
    for (int i = 0; i < edgeNumbers; i++) {
        scanf("%d %d %d", &graph[i].vertex1, &graph[i].vertex2, &graph[i].weight);
    }
}

/**
 * @brief Kruskal算法
 */
void kruskal() {
    // 总权重初始化为0
    int totalWeight = 0;
    // 已经连接的边初始化为0
    int connectedEdge = 0;
    // 存储顶点的父节点
    int parent[vertexNumbers];
    // 对权重进行升序排序
    sort(graph, graph+vertexNumbers, comparator);
    // 使每个顶点的父节点为自己本身
    for (int i = 0; i < vertexNumbers; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < edgeNumbers; i++) {
        int vertex1 = graph[i].vertex1;
        int vertex2 = graph[i].vertex2;
        int weight = graph[i].weight;

        int vertex1Parent = findParent(parent, vertex1);
        int vertex2Parent = findParent(parent, vertex2);
        // 两个顶点的父节点相等则说明他们构成环了
        if (vertex1Parent != vertex2Parent) {
            totalWeight += weight;
            connectedEdge++;
            // 使两个顶点的父节点统一为一个
            parent[vertex1Parent] = vertex2Parent;
            MST.push_back(graph[i]);
        }

    }
    if (connectedEdge == vertexNumbers -1) {
        for (Node edge : MST) {
            cout << edge.vertex1 << "-->" << edge.vertex2 
                 << " and weight is " << edge.weight << endl;
        }
        cout << "Total weight is " << totalWeight << endl;
    } else {
        cout << "MST is not existed" << endl;
        return;
    }
}

int main() {
    freopen(PATH, "r", stdin);
    createGraph();
    kruskal();
	return 0;
}
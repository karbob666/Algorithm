#include <iostream>
#include <cstring>
#include <cmath>

#define PATH "input.txt" 

using namespace std;

const int MAX_SIZE = 1e3 + 3;
const int INF = 0x3f3f3f3f; // 无穷大

// 总的顶点个数和总的边数
int vertexNumbers, edgeNumbers; 
// 存储相关顶点边的权值
int lowcost[MAX_SIZE];  
// 存储相关顶点的下标
int vertexIndex[MAX_SIZE];  
int graph[MAX_SIZE][MAX_SIZE];  

/**
 * @brief 对图进行prim算法遍历
 * 
 * @param startVertex 从这个顶点开始遍历图
 */
void prim(int startVertex) {
    // minWeight是最小权重, nextVertex是权重最小的顶点
    int minWeight, nextVertex;
    // 总共权重
    int totalWeight = 0;
    
    // 初始化操作
    for (int i = 0; i < vertexNumbers; i++) {
        // lowcost=0代表该点已经被访问过了, 如果不等于0就是等于该顶点的边权重
        lowcost[i] = i == startVertex ? 0 : graph[startVertex][i]; 
        vertexIndex[i] = startVertex;
    }
    
    for (int i = 0; i < vertexNumbers; i++) {
        minWeight = INF;
        for (int j = 0; j < vertexNumbers; j++) {
            if (lowcost[j] != 0 && lowcost[j] < minWeight) {
                minWeight = lowcost[j];
                nextVertex = j;
            }
        }
        if (minWeight == INF) break;
        // 总权重增加
        totalWeight += minWeight;
        // 下一条边的最小权重设置为0, 代表该顶点已经访问过了
        lowcost[nextVertex] = 0;
        // 输出当前顶点边中权值最小的边
        cout << vertexIndex[nextVertex] << "-->" << nextVertex << endl;
        // 更新新节点
        for (int j = 0; j < vertexNumbers; j++) {
            if (lowcost[j] != 0 &&  graph[nextVertex][j] < lowcost[j]) {
                lowcost[j] = graph[nextVertex][j];
                vertexIndex[j] = nextVertex;
            }
        }
    } 
    // 输出总权重
    cout << "Total weight is " << totalWeight << endl;
} 
/**
 * @brief 建图
 */
void createGraph() {
    int vertex1, vertex2, weight;
    // 初始化所有顶点的边权重为无穷大
    memset(graph, INF, sizeof(graph));
    scanf("%d %d", &vertexNumbers, &edgeNumbers);
    for (int i = 0; i < edgeNumbers; i++) {
        scanf("%d %d %d", &vertex1, &vertex2, &weight);
        graph[vertex1][vertex2] = weight;
        graph[vertex2][vertex1] = weight;
    }
}

/**
 * @brief 主函数
 * 
 * @return int 
 */
int main() {
    freopen(PATH, "r", stdin);
    createGraph();
    prim(0);
    fclose(stdin);
	return 0;
}


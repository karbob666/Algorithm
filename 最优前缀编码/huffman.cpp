#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1e3 + 3;

struct Node {
    int value, id;
    bool friend operator<(const Node& a, const Node& b) {
        //按照键值降序排序
        if (a.value != b.value)
            return a.value > b.value;
        return a.id > b.id;
    }
};

struct Tree {
    int left;      // 左子树
    int right;     // 右子树
    int value;     // 值
} tree[MAX];

int n;     // 字符集个数
string s;   // 字符集
priority_queue<Node> q;
int parent[MAX];
string haffmanCode[MAX];

void getHaffmanCode() {
    // 从叶子节点开始跳到祖先节点
    for (int i = 1; i <= n; i++) {
        string temp;
        int j = i;
        while (parent[j] > 0) {
            temp = (j == tree[parent[j]].left ? '0' : '1') + temp;
            j = parent[j];
        }
        haffmanCode[i] = temp;
    }
}

void haffmanAlgoirithm() {
    // 哈夫曼算法最多执行n-1次
    for (int i = 1; i < n; i++) {
        // 每次从堆中取出2个值最小的节点
        Node a = q.top();
        q.pop();
        Node b = q.top();
        q.pop();

        int id = i + n;
        int value = a.value + b.value;

        // 建立树结构
        tree[id].left = a.id;
        tree[id].right = b.id;
        tree[id].value = value;
        parent[a.id] = id;
        parent[b.id] = id;
        q.push({value, id});
    }
    getHaffmanCode();
}

int main() {
    int value;
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &value);
        q.push({value, i});
    }
    haffmanAlgoirithm();
    // 输出最优前缀编码
    for (int i = 1; i <= n; i++) {
        cout << s[i-1] << ":" << haffmanCode[i] << endl;
    }
}

/*
输入
ABCDEFG
10 15 12 3 4 13 1
 */
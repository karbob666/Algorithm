#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e3 + 3;

int n;              // n项任务
int m;              // m为totalTime/2，总时间的一半，实际上是背包容量
int totalTime = 0;  // n项任务所需的总时间
int t[MAX];         // t[i]代表的是第i个任务加工所需的时间
int dp[MAX];        // 动态规划一维数组
int first[MAX];     // 第一台机器选择的任务,first[i]表示第一台机器选择第i个任务
int choice[MAX][MAX];   // 记录选择状态

/**
 * @brief 01背包问题，动态规划计算出加工时间最小的调度方案
 * 
 */
void knapsack() {
    // 初始化
    memset(dp, 0, sizeof(dp));
    memset(choice, 0, sizeof(choice));
    for (int i = 1; i <= n; i++) {
        for (int j=m; j>= t[i]; j--) {
            if (dp[j] < dp[j-t[i]]+t[i]) {
                choice[i][j] = i;
                dp[j] = dp[j-t[i]]+t[i];
            }
        }
    }
}

/**
 * @brief 打印出任务分配情况
 * 
 */
void print() {
    int i = n;
    int j = m;
    // 初始化
    memset(first, 0, sizeof(first));
    // 从一维数组dp自底向上遍历
    while (i-- && j) {
        if (choice[i][j]) {
            first[i] = 1;
            j -= t[i];
        }
    }
    // 打印第一台机器任务分配情况
    cout << "The task for the first machine:";
    for (int i = 1; i <= n; i++) {
        if (first[i]) {
            cout << "t" << i << " ";
        }
    }
    cout << ",it takes " << dp[m] << endl;

    // 第一台机器分配完成，剩下的就是第二台机器的任务
    cout << "The task for the second machine:";
    for (int i = 1; i <= n; i++) {
        if (!first[i]) {
            cout << "t" << i << " ";
        }
    }
    cout << ",it takes " << totalTime-dp[m] << endl;
}

int main() {
    cout << "Please input the number of task:";
    scanf("%d", &n);
    cout << "Please input the time spent on each task:";
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        totalTime += t[i];
    }
    m = totalTime / 2;
    knapsack();
    print();
    cout << "The shortest time is " << max(dp[m], totalTime-dp[m]) << endl;
}

/*
输入
5
1 5 2 10 3
 */

/*
输出
The task for the first machine:t4 ,it takes 10
The task for the second machine:t1 t2 t3 t5 ,it takes 11
The shortest time is 11
 */
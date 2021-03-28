#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX = 200;

/**
 * @brief 顺序查找
 * 
 * @param array 数组
 * @param target 目标数字
 * @param start 开始的下标
 * @param end 结束的下标
 * @return int 目标数字的下标
 */
int traversalSearch(int array[], int target, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return 0;
}

int main() {
    int x, size, index;
    int data[1003];
    cout << "Please input a number(1~200):";
    scanf("%d", &x);
    // 随机生成200个1~200的数据
    srand(time(NULL));
    for (int i = 1; i <= MAX; i++) {
        data[i] = 1 + (rand() % MAX);
    }
    // 对随机生成的数据进行排序
    sort(data+1, data+MAX+1);
    // 对排好序的数据进行去重, size是排好序之后数组的大小
    size = unique(data+1, data+MAX+1) - data;
    // index是寻找到输入数据的数组下标, 如果没找到index=0
    index = traversalSearch(data, x, 1, MAX);
    cout << "index = " << index << endl;
}

#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 1e3 + 3;

void merge(int array[], int start, int middle, int end) {
    
    // 以middle为分界线, 分为两个部分
    int startIndex1 = start;
    int endIndex1 = middle;
    int startIndex2 = middle+1;
    int endIndex2 = end;
    
    // 临时数组, SIZE是数组大小
    const int SIZE = end - start + 1;
    int temp[SIZE];
    int count = 0;

    // 以middle为分界线, 处理左边和右边的数组
    while (startIndex1 <= endIndex1 && startIndex2 <= endIndex2) {
        temp[count++] = array[startIndex1] < array[startIndex2] ? array[startIndex1++] : array[startIndex2++];
    }
    // 左边有剩余
    while (startIndex1 <= endIndex1) {
        temp[count++] = array[startIndex1++];
    }
    // 右边有剩余
    while (startIndex2 <= endIndex2) {
        temp[count++] = array[startIndex2++];
    }
    // 将处理好的temp数组, 替换下标start到下标end之间的数据
    for (int i = 0; i < SIZE; i++) {
        array[start+i] = temp[i];
    }

}

void mergeSort(int array[], int start, int end) {
    int middle = (start+end) / 2;
    if (start < end) {
        // 递归拆分左边数组进行排序
        mergeSort(array, start, middle);
        // 递归拆分右边数组进行排序
        mergeSort(array, middle+1, end);
        // 将数组归并
        merge(array, start, middle, end);
    }
}

int main() {
    
    int a[N];
    // 生成N个0-N的数
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        a[i] = rand() % (N+1);
    }
    // 进行二分归并排序
    mergeSort(a, 0, N-1);
    // 输出排好序的数据
    for (int i = 0; i < N; i++) {
        cout << a[i] << endl;
    }
}
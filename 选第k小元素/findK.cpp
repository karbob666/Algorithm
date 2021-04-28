#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int findK(vector<int> a, int left, int right, int k) {
    
    int i = left;
    int j = right;
    // 选取第一个元素作为主元p
    int p = a[i];
    // 快排
    while (i < j) {
        while (i < j && a[j] >= p) {
            j--;
        }
        while (i < j && a[i] <= p) {
            i++;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    // 交换主元和第i位置的元素
    swap(a[left], a[i]);

    // 左区间元素个数
    int amount = i-left + 1;
    // 当amount个数等于k的时候找到第k小元素
    if (amount == k) {
        return p;
    }
    // amount < k 代表左区间元素个数小于k, 那么第k小元素在右区间
    if (amount < k) {
        return findK(a, i+1, right, k-amount);
    } else {
        return findK(a, left, i, k);
    }
}

int main() {
    int n, k;
    vector<int> a;
    srand(time(NULL));
    // 随机生成n个整数0-100的整数
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        a.push_back(rand() % (100+1));
        cout << a[i] << endl;
    }
    cout << "The result is " << findK(a, 0, n-1, k) << endl;
}
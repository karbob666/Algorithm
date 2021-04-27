#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 1e3 + 3;

struct point {
    double x;
    double y;
};

/**
 * @brief 比较器, 将x轴的点按升序排序
 */
bool comparatorX(const point p1, const point p2) {
    return p1.x < p2.x;
}

/**
 * @brief 比较器, 将y轴的点按升序排序
 */
bool comparatorY(const point p1, const point p2) {
    return p1.y < p2.y;
}

/**
 * @brief 计算两个点之间的距离
 */
double computeDistance(const point p1, const point p2) {
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

/**
 * @brief 获取最近点对的距离
 */
double getClosestDistance(vector<point> points) {
    // 只有两个点
    if (points.size() == 2) {
        return computeDistance(points[0], points[1]);
    }
    // 只有三个点
    if (points.size() == 3) {
        return min(computeDistance(points[0], points[1]), 
                   min(computeDistance(points[0], points[1]), computeDistance(points[1], points[2])));
    }
    
    // 点的个数大于三个
    int middle  = points.size() / 2;
    // 容器的左边的点
    vector<point> left(points.begin(), points.begin()+middle);
    // 容器的右边的点
    vector<point> right(points.begin()+middle+1, points.end());
    // 当两个点都在左边或右边的时候, cloest是左右集合中最小的距离
    double closest = min(getClosestDistance(left), 
                         getClosestDistance(right));
    // 当一个点在左边一个点在右边的时候, 将|x-points[middle]|<closest点放进容器里
    // 即将x轴到中线x轴的距离小于closest的点放进p容器里边
    vector<point> p;
    for (int i = 0; i < points.size(); i++) {
        if (fabs(points[i].x - points[middle].x) < closest) {
            p.push_back(points[i]);
        }
    }
    // 对y轴的点按升序排序
    sort(p.begin(), p.end(), comparatorY);
    // 寻找最小点对
    for (int i = 0; i < p.size(); i++) {
        for (int j = i+1; j < p.size(); j++) {
            closest = min(closest, computeDistance(p[i], p[j]));
        }
    }
    return closest;
}

int main() {
    int n;
    vector<point> points;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        point point;
        scanf("%lf %lf", &point.x, &point.y);
        points.push_back(point);
    }
    // 对x轴的点按升序排序
    sort(points.begin(), points.end(), comparatorX);
    cout << "The closest distance is " << getClosestDistance(points) << endl;
    return 0;
}
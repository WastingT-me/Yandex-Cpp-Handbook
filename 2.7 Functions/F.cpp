#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y;

    int distanceSquared() const {
        return x * x + y * y;
    }
};

bool compare(const Point& a, const Point& b) {
    return a.distanceSquared() < b.distanceSquared();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::sort(points.begin(), points.end(), compare);

    for (const auto& point : points) {
        std::cout << point.x << " " << point.y << std::endl;
    }

    return 0;
}
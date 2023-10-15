#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXSIZE = 300000;

struct Edge {
    int u, v;
    double w;
};

struct Point {
    int x, y;
};

int p[MAXSIZE];
vector<Edge> g;
vector<Point> points;

int parent(int i) {
    return i == p[i] ? i : parent(p[i]);
}

double kruskal(int c) {
    int n = points.size();
    sort(g.begin(), g.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    double ans = 0.0;

    for (int i = 0; i < c; ++i) {
        int u = parent(g[i].u);
        int v = parent(g[i].v);

        if (u != v) {
            p[u] = p[v];
            ans += g[i].w;
        }
    }

    return ans;
}

double dist(const Point& a, const Point& b) {
    return hypot(b.x - a.x, b.y - a.y);
}

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int n;
        cin >> n;

        g.clear();
        points.resize(n);

        for (int i = 0, k = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
            for (int j = 0; j < i; ++j) {
                g.push_back({j, i, dist(points[j], points[i]) / 100.0});
            }
        }

        g.reserve(n * (n - 1) / 2); // Preallocate memory for edges

        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }

        cout.precision(2);
        cout << fixed << kruskal(g.size()) << endl;
    }

    return 0;
}

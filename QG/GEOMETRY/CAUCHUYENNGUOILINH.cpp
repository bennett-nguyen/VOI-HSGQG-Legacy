#include <bits/stdc++.h>

namespace Geometry {
    // Constants
    #define EPSILON 0.000000001

    // Misc
    double hypot(const double b, const double c) {
        return std::sqrt(b*b + c*c);
    }

    double to_rads(const double degree) {
        return degree * M_PI / 180.0;
    }

    double to_deg(const double rads) {
        return rads * 180.0 / M_PI;
    }

    bool fequal(const double a, const double b) {
        return std::abs(a-b) < EPSILON;
    }

    // Geometry Objects
    struct Point {
        double x, y;

        Point() { x = 0; y = 0; }
        Point(double _x, double _y) { x = _x; y = _y; }

        bool operator<(const Point other) const {
            if (fequal(x, other.x)) return y < other.y;
            return x < other.x;
        }

        bool operator==(const Point other) const {
            return (fequal(x, other.x) && fequal(y, other.y));
        }

        Point projection_on_x_axis() {
            return Point(x, 0);
        }

        Point projection_on_y_axis() {
            return Point(0, y);
        }

        std::pair<int, int> to_pair() {
            return std::make_pair(x, y);
        }
    };

    struct Line {
        double a, b, c;

        Line(const Point A, const Point B) {
            if (A.x == B.y) {
                a = 1;
                b = 0;
                c = -A.x;
            } else {
                a = (B.y - A.y) / (A.x - B.x);
                b = 1;
                c = -a * A.x - A.y;
            }
        }
    };

    struct Vector2 {
        double x, y;
        Vector2(const double _x, const double _y) { x = _x; y = _y; }
        Vector2(const Point A, const Point B) {
            x = B.x - A.x;
            y = B.y - A.y;
        }

        Vector2 operator+(const Vector2 other) const {
            return Vector2(x+other.x, y+other.y);
        }

        Vector2 operator-(const Vector2 other) const {
            return Vector2(x-other.x, y-other.y);
        }
    
        Vector2 operator*(const double k) const {
            return Vector2(x*k, y*k);
        }

        bool operator==(const Vector2 other) const {
            return (fequal(x, other.x) && fequal(y, other.y));
        }

        double magnitude() {
            return hypot(x, y);
        }

        double magnitude_sq() {
            return x*x + y*y;
        }

        double dot(const Vector2 other) {
            return x * other.x + y * other.y;
        }

        double cross(const Vector2 other) {
            return x * other.y - y * other.x;
        }

        std::pair<int, int> to_pair() {
            return std::make_pair(x, y);
        }
    };

    // Point Operations
    Point translate(const Point A, const Vector2 v) {
        return Point(A.x+v.x, A.y+v.y);
    }

    double dist(const Point A, const Point B) {
        return hypot(A.x-B.x, A.y-B.y);
    }

    bool CCW(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);
        return OA.cross(OB) > 0;
    }

    bool CW(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);
        return OA.cross(OB) < 0;
    }

    bool are_collinear(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);
        return OA.cross(OB) < EPSILON;
    }

    Point rotation(const Point P, const double alpha) {
        return Point(
            P.x * std::cos(alpha) - P.y * std::sin(alpha),
            P.x * std::sin(alpha) + P.y * std::cos(alpha)
        );
    }

    // Line Operations
    bool are_parallel(const Line d1, const Line d2) {
        return fequal(d1.a, d2.a) && fequal(d1.b, d2.b);
    }

    bool are_coincident(const Line d1, const Line d2) {
        return are_parallel(d1, d2) && fequal(d1.c, d2.c);
    }

    bool are_intersect(const Line d1, const Line d2) {
        return !are_parallel(d1, d2);
    }


    Point intersection(const Line d1, const Line d2) {
        if (!are_intersect(d1, d2)) return Point(INT_MIN, INT_MIN);
        double D = (d1.a * d2.b - d1.b * d2.a);
        double Dx = (d1.c * d2.b - d1.b * d2.c);
        double Dy = (d1.a * d2.c - d1.c * d2.a);

        return Point(Dx/D, Dy/D);
    }

    double get_angle(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);

        return std::acos(
            OA.dot(OB) /
            std::sqrt(OA.magnitude_sq()+OB.magnitude_sq())
        );
    }

    double dist_to_line(const Point M, const Point P1, const Point P2) {
        Vector2 P1M(P1, M), P1P2(P1, P2);
        double k = P1M.dot(P1P2) / P1P2.magnitude_sq();

        Point H = translate(P1, P1P2*k);
        return dist(M, H);
    }

    // Circles
    double circle_perimeter(const double radius) {
        return 2*M_PI*radius;
    }

    double circle_area(const double radius) {
        return M_PI*radius*radius;
    }

    // Polygons
    double perimeter(const std::vector<Point> &polygon) {
        int num_points = polygon.size();
        double res = 0;

        for (int current = 0; current < num_points; current++) {
            int next = (current+1) % num_points;
            Point current_p = polygon[current];
            Point next_p = polygon[next];

            res += dist(current_p, next_p);
        }

        return res;
    }

    double area(const std::vector<Point> &polygon) {
        int num_points = polygon.size();
        double res = 0;

        for (int current = 0; current < num_points; current++) {
            int next = (current+1) % num_points;
            Point current_p = polygon[current];
            Point next_p = polygon[next];

            res += current_p.x * next_p.y - current_p.y * next_p.x;
        }

        return std::abs(res) / 2;
    }

    bool inside_polygon(const Point M, const std::vector<Point> &polygon) {
        int num_points =  polygon.size();
        if (num_points < 3) return false;

        double sum = 0;
        for (int current = 0; current < num_points; current++) {
            int next = (current+1) % num_points;
            Point current_p = polygon[current];
            Point next_p = polygon[next];

            sum += get_angle(M, current_p, next_p);
        }

        return fequal(std::abs(sum), 2*M_PI);
    }

    // Constant Objects
    const Point O(0, 0);
    const Vector2 VectZero(0, 0);
}

using namespace std;
using namespace Geometry;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n, res = 0;
vector<Point> p;
vector<Point> new_p;

void convex_hull(vector<Point> &points) {
    vector<Point> p = points;

    int num_points = points.size();
    if (num_points <= 3) {
        res++;
        return;
    }

    int t = 0;

    FOR(i, 1, n-1) {
        if (p[i].to_pair() < p[t].to_pair()) t = i;
    }

    swap(p[t], p[0]);
    Point pivot = p[0];
    sort(++p.begin(), p.end(), cmp);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    FOR(i, 1, n) {
        int x, y;
        cin >> x >> y;
        p.push_back(Point(x, y));
    }

    convex_hull(p);

    return 0;
}
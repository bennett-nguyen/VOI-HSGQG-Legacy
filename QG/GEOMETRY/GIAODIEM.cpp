#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

namespace Geometry {
    // Constants
    #define EPSILON 0.000000001

    // Geometry Objects
    struct Point {
        double x, y;

        Point() { x = 0; y = 0; }
        Point(double _x, double _y) { x = _x; y = _y; }

        bool operator<(const Point B) const {
            if (std::abs(x - B.x) < EPSILON) return y < B.y;
            return x < B.x;
        }

        bool operator==(const Point B) const {
            return (std::abs(x - B.x) < EPSILON && std::abs(y - B.y) < EPSILON);
        }

        Point projection_on_x_axis() {
            return Point(x, 0);
        }

        Point projection_on_y_axis() {
            return Point(0, y);
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

        Vector2 operator*(double k) const {
            return Vector2(x*k, y*k);
        }

        double magnitude() {
            return hypot(x, y);
        }

        double magnitude_sq() {
            return x*x + y*y;
        }
    };

    // Vector Operations
    double dot(const Vector2 v1, const Vector2 v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    double cross(const Vector2 v1, const Vector2 v2) {
        return v1.x * v2.y - v1.y * v2.x;
    }


    // Line Operations
    bool are_parallel(const Line d1, const Line d2) {
        return d1.a == d2.a && d1.b == d2.b;
    }

    bool are_coincident(const Line d1, const Line d2) {
        return are_parallel(d1, d2) && d1.c == d2.c;
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

    // Misc
    double hypot(const double b, const double c) {
        return sqrt(b*b + c*c);
    }

    double get_angle(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);

        return std::acos(
            dot(OA, OB) /
            std::sqrt(OA.magnitude_sq() + OB.magnitude_sq())
        );
    }

    // Point Operations
    Point translate(const Point A, const Vector2 v) {
        return Point(A.x+v.x, A.y+v.y);
    }

    double dist(const Point A, const Point B) {
        return hypot(A.x-B.x, A.y-B.y);
    }

    bool CCW(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);
        return cross(OA, OB) > 0;
    }

    bool CW(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);
        return cross(OA, OB) < 0;
    }

    bool are_collinear(const Point O, const Point A, const Point B) {
        Vector2 OA(O, A), OB(O, B);
        return cross(OA, OB) == 0;
    }

    Point rotation(const Point P, const double alpha) {
        return Point(
            P.x * std::cos(alpha) - P.y * std::sin(alpha),
            P.x * std::sin(alpha) + P.y * std::cos(alpha)
        );
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

        return (std::abs(sum) - M_2_PI) < EPSILON;
    }

    // Constants Objects
    const Point O(0, 0);
}

using Geometry::Line, Geometry::Point;

int n;
vector<Line> v;

double max_height = -1;
int x, y;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Line(Point(a, 0), Point(b, c)));
    }

    FOR(i, 1, v.size()-1) {
        FOR(j, 0, i-1) {
            Point I = intersection(v[i], v[j]);

            double height = dist(I, I.projection_on_x_axis());
            if (height > max_height) {
                x = j;
                y = i;
                max_height = height;
            }
        }
    }

    if (max_height == -1) {
        cout << setprecision(3) << fixed << max_height;
    } else {
        cout << setprecision(3) << fixed << max_height << el;
        cout << x+1 << ' ' << y+1;
    }

    return 0;
}
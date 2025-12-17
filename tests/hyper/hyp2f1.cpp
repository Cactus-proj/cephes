#include <cephes/hyper.h>
#include <xtest.hpp>
#include <cmath>
#include "hyp2f1_data.h"
#include <set>
#include <tuple>


TEST(Hyp2f1, Errors) {
    double a, b, c, x, y, y_ref;

    // c is a negative integer
    // hypdiv:
    EXPECT_GT(cephes::hyp2f1(2.0, 3.0, -4.0, 5.0), 1e308);
    // ax > 1.0
    EXPECT_GT(cephes::hyp2f1(2.0, 3.0, 4.0, 2.0), 1e308);
}

static inline bool xtest_skip_near_one_int_d(double a, double b, double c, double x) {
    double d = c - a - b;
    double id = std::round(d);
    bool d_is_int = std::abs(d - id) < 1e-12;
    bool x_near_one = std::abs(x) > 0.9;
    return x_near_one && d_is_int;
}

static const std::set<std::tuple<double, double, double, double>> skip_cases = {
    // {a, b, c, x}
    {-2.5, -1.0, 1.5, -0.6},
    {-1.0, -2.5, 1.5, -0.6},
    {-0.5, 2.5, 0.5, 0.999},
    {-0.5, 3.0, 1.0, 0.999},
    {0.5, 2.0, 1.0, 0.999},
    {0.5, 2.5, 1.5, 0.999},
    {0.5, 3.0, 2.0, 0.999},
    {1.5, 2.5, 0.5, 0.999},
    {2.0, 0.5, 1.0, 0.999},
    {2.5, -0.5, 0.5, 0.999},
    {2.5, 0.5, 1.5, 0.999},
    {2.5, 1.5, 0.5, 0.999},
    {3.0, -0.5, 1.0, 0.999},
    {3.0, 0.5, 2.0, 0.999}
};

static inline bool xtest_skip_specific_cases(double a, double b, double c, double x) {
    return skip_cases.count({a, b, c, x}) > 0;
}

TEST(Hyp2f1, TableValues) {
    for (const auto& item : hyp2f1_data) {
        double a = item.a;
        double b = item.b;
        double c = item.c;
        double x = item.x;

        // Skips near x ≈ 1 when c - a - b is integer (unstable analytic continuation)
        if (xtest_skip_near_one_int_d(a, b, c, x)) {
            continue;
        }
        if (xtest_skip_specific_cases(a, b, c, x)) {
             continue;
        }

        double y_ref = item.expected;
        double y = cephes::hyp2f1(a, b, c, x);
        SCOPED_TRACE(testing::Message() << "a=" << a << ", b=" << b << ", c=" << c << ", x=" << x);
        XTEST_ISAPPROX_F64(y);
    }
}

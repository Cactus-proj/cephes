#include <cephes/hyper.h>
#include <xtest.hpp>
#include "hyperg_data.h"
#include <set>
#include <tuple>
#include <limits>

// Hyperg， 1F1, M(a,b,z)
TEST(Hyperg, SpecialValues) {
    // b is negative integer or zero (singular)
    EXPECT_GT(cephes::hyperg(1.0, -2.0, 1.0), 1e308);
    EXPECT_GT(cephes::hyperg(1.0, 0.0, 1.0), 1e308);
}


// TODO: broken test cases
static const std::set<std::tuple<double, double, double>> broken_set{
    {1.0, 2.0, 5.0},
    {1.0, 3.0, 5.0},
    {1.0, 2.0, 10.0},
    {1.0, 3.0, 10.0},
    {1.0, 4.0, 10.0},
    {1.0, 5.0, 10.0},
    {1.0, 3.0, 20.0},
    {1.0, 3.5, 20.0},
    {1.0, 4.0, 20.0},
    {1.0, 5.0, 20.0},
    {2.0, 5.0, 20.0},
};

static bool is_broken(double a, double b, double x) {
    return broken_set.count(std::tuple<double, double, double>{a, b, x}) != 0;
}

TEST(Hyperg, CoSF_Table12_Values) {
    for (const auto& item : hyperg_data) {
        double a = item.a;
        double b = item.b;
        double x = item.x;
        double y_ref = item.expected;
        if (is_broken(a, b, x)) {
            continue;
        }

        double y = cephes::hyperg(a, b, x);
        SCOPED_TRACE(testing::Message() << "a=" << a << ", b=" << b << ", x=" << x);
        XTEST_ISAPPROX_F64(y);
    }
}

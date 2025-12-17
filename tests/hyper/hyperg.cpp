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

TEST(Hyperg, Coverage) {
    double a, b, c, x, y, y_ref;

    /* hy1f1a x=0 Branch (Defensive/Dead code) `if (x == 0) {`
        To reach hy1f1a with x=0, hy1f1p must fail (err >= 1e-15).
        For x=0, hy1f1p is perfect.
        The only way to bypass is if pcanc is NaN (NaN < 1e-15 is False).
        This forces execution of the x=0 check in hy1f1a.
    */
    if (std::numeric_limits<double>::has_quiet_NaN) {
        a = std::numeric_limits<double>::quiet_NaN();
        b = 1.0;
        x = 0.0;
        y = cephes::hyperg(a, b, x);
        EXPECT_TRUE(std::isnan(y));
    }

    /* hy1f1a Negative b:  `if (b < 0) {`
        Large negative x to force asymptotic. b negative non-integer.

        Hypergeometric1F1[1.5, -1.5, -50] = -6.23434*10^-17
    */
    a = 1.5; b = -1.5; x = -50.0;
    y = cephes::hyperg(a, b, x);
    y_ref = 0.0;
    // EXPECT_REL_NEAR_F64(y, y_ref);  // TODO: broken y=994849612.33212531

    /* hyp2f0 Overflow : `if ((temp > 1.0) && (maxt > (MAXNUM / temp))) goto error;`
        TODO:
    */
    a = 1e10; b = 2.0; x = -100.0;
    // y = cephes::hyperg(a, b, x);
    // XTEST_ISAPPROX_F64(y, ???);

    /* hyp2f0 Loop Limit (n > 200): `if (n > 200) goto ndone;`

        TODO:
    */
    a = 2.0; b = 4.0; x = 1000.0;
    // y = cephes::hyperg(a, b, x);
    // XTEST_ISAPPROX_F64(y, ???);
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

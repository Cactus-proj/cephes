#include <limits>
#include <complex>
#include <cephes/bessel.h>
#include <xtest.hpp>

TEST(BesselJ0, BasicAssertions) {
    double x, y, y_ref;
}
TEST(BesselJ0, Branches) {
    double x, y, y_ref;

    // x <= 5.0 && x < 1.0e-5
    EXPECT_EQ(cephes::j0(0.0), 1.0);

    // 1.0e-5 <= x <= 5.0
    x = 1.0;
    y = cephes::j0(x);
    y_ref = 0.7651976865579666;
    XTEST_ISAPPROX_F64(y);
    x = 2.0;
    y = cephes::j0(x);
    y_ref = 0.2238907791412356;
    XTEST_ISAPPROX_F64(y);
    x = 3.0;
    y = cephes::j0(x);
    y_ref = -0.2600519549019333;
    XTEST_ISAPPROX_F64(y);
    x = 4.0;
    y = cephes::j0(x);
    y_ref = -0.3971498098638473;
    XTEST_ISAPPROX_F64(y);
    x = 5.0;
    y = cephes::j0(x);
    y_ref = -0.1775967713143385;
    XTEST_ISAPPROX_F64(y);

    // x > 5.0
    x = 10.0;
    y = cephes::j0(x);
    y_ref = -0.2459357644513642;
    XTEST_ISAPPROX_F64(y);
    x = 100.0;
    y = cephes::j0(x);
    y_ref = 0.01998585030422333;
    XTEST_ISAPPROX_F64(y);
    x = 1000.0;
    y = cephes::j0(x);
    y_ref = 0.02478668615242003;
    XTEST_ISAPPROX_F64(y);
}

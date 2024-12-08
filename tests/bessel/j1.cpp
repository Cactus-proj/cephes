#include <limits>
#include <complex>
#include <cephes/bessel.h>
#include <xtest.hpp>

TEST(BesselJ1, BasicAssertions) {
    EXPECT_EQ(cephes::j1(0.0), 0.0);
    EXPECT_EQ(cephes::j1(-0.0), 0.0);
}
TEST(BesselJ1, Branches) {
    double x, y, y_ref;

    // x <= 5.0
    x = 1.0;
    y = cephes::j1(x);
    y_ref = 0.4400505857449335;
    XTEST_ISAPPROX_F64(y);
    x = 2.0;
    y = cephes::j1(x);
    y_ref = 0.5767248077568736;
    XTEST_ISAPPROX_F64(y);
    x = 5.0;
    y = cephes::j1(x);
    y_ref = -0.3275791375914652;
    XTEST_ISAPPROX_F64(y);

    // x > 5.0
    x = 10.0;
    y = cephes::j1(x);
    y_ref = 0.04347274616880752;
    XTEST_ISAPPROX_F64(y);
    x = 100.0;
    y = cephes::j1(x);
    y_ref = -0.07714535201411228;
    XTEST_ISAPPROX_F64(y);
    x = 1000.0;
    y = cephes::j1(x);
    y_ref = 0.00472831190708902;
    XTEST_ISAPPROX_F64(y);
}

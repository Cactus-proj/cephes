#include <xtest.hpp>
#include <cephes/bessel.h>


TEST(BesselJn, BasicAssertions) {
    EXPECT_REL_NEAR_F64(cephes::jn(5, 1.0), 0.0002497577302112345);
    EXPECT_REL_NEAR_F64(cephes::jn(10, 1.0), 2.630615123687453e-10);
    EXPECT_REL_NEAR_F64(cephes::jn(50, 1.0), 2.906004948173273e-80);
    EXPECT_REL_NEAR_F64(cephes::jn(100, 1.0), 8.43182878962688e-189);
}
TEST(BesselJ1, Branches) {
    // n < 0
    EXPECT_REL_NEAR_F64(cephes::jn(-1, 0.0), 0.0);
    EXPECT_TRUE(std::isnan(cephes::jn(-2, 0.0)));

    // x < 0.0
    EXPECT_REL_NEAR_F64(cephes::jn(0, -1.0), 0.7651976865579666);
    EXPECT_REL_NEAR_F64(cephes::jn(1, -1.0), -0.4400505857449335);

    // n = 0,1,2
    EXPECT_REL_NEAR_F64(cephes::jn(0, 1.0), 0.7651976865579666);
    EXPECT_REL_NEAR_F64(cephes::jn(1, 1.0), 0.4400505857449335);
    EXPECT_REL_NEAR_F64(cephes::jn(2, 1.0), 0.1149034849319005);

    // x < MACHEP
    EXPECT_REL_NEAR_F64(cephes::jn(5, 0.0), 0.0);
}

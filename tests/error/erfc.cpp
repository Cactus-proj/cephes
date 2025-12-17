#include <cephes/error.h>
#include <xtest.hpp>

TEST(ErfC, SpecialValues) {
    // x = 0 -> erfc(0) = 1
    EXPECT_EQ(cephes::erfc(0.0), 1.0);
    EXPECT_EQ(cephes::erfc(-0.0), 1.0);

    // Large-argument limit: x >> 1 -> erfc(x) -> 0
    // erfc(+∞) returns +0
    EXPECT_REL_NEAR_F64(cephes::erfc(20.0), 0.0);
    EXPECT_EQ(cephes::erfc(xtest::Inf64), 0.0);

    // Large negative argument: x << -1 -> erfc(x) -> 2
    // erfc(−∞) returns 2
    EXPECT_REL_NEAR_F64(cephes::erfc(-20.0), 2.0);
    EXPECT_EQ(cephes::erfc(-xtest::Inf64), 2.0);

    // Relation: erfc(x) = 1 - erf(x)
    EXPECT_REL_NEAR_F64(cephes::erfc(1.0), 1.0 - cephes::erf(1.0));
}

TEST(ErfC, Branches) {
    // z < -MAXLOG && a < 0
    EXPECT_REL_NEAR_F64(cephes::erfc(-20.0), 2.0);
}

#include <cephes/misc.h>
#include <xtest.hpp>

TEST(PloyLog, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::polylog(-1, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::polylog(0, xtest::NaN64)));

    // NOTE: inf loop
    // DOMAIN error
    // EXPECT_EQ(cephes::polylog(-10, xtest::NaN64), 0.0);
    // EXPECT_EQ(cephes::polylog(-2, xtest::NaN64), 0.0);
    // EXPECT_EQ(cephes::polylog(2, xtest::NaN64), 0.0);
    // EXPECT_EQ(cephes::polylog(10, xtest::NaN64), 0.0);

    EXPECT_TRUE(std::isinf(cephes::polylog(-1, 1.0)));
    EXPECT_TRUE(std::isinf(cephes::polylog(0, 1.0)));
    EXPECT_TRUE(std::isinf(cephes::polylog(1, 1.0)));
}

/*

*/
TEST(PloyLog, Branches) {
    // if (n == -1)
    // if (n == 0)
    // if (n == 1)
    // if (x == 1.0 && n > 1)
    // if (x == -1.0 && n > 1)
    // if (x < -1.0 && n > 1)
    // if (n == 2)

    // if (n == 3) && if (x > 0.8)
    // if (n == 4) && if (x >= 0.875)

    // if (x < 0.75)
    // !(x < 0.75)
}

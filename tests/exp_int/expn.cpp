#include <cephes/exp_int.h>
#include <xtest.hpp>

TEST(ExpN, Errors) {
    // n < 0
    EXPECT_TRUE(cephes::expn(-1, 10.0) > 1e308);
    // x < 0
    EXPECT_TRUE(cephes::expn(1, -1.0) > 1e308);
    // x > MAXLOG ≈ 709.78
    EXPECT_EQ(cephes::expn(1, 800), 0.0);
    // x==0 && n < 2
    EXPECT_TRUE(cephes::expn(1, 0.0) > 1e308);
    EXPECT_TRUE(cephes::expn(0, 0.0) > 1e308);
}
TEST(ExpN, CodecovTodo) {
    const double nan64 = std::numeric_limits<double>::quiet_NaN();

    // x==0.0 && n >= 2
    EXPECT_NE(cephes::expn(2, 0.0), nan64);
    EXPECT_NE(cephes::expn(10, 0.0), nan64);
    // n==0
    EXPECT_NE(cephes::expn(0, 10.0), nan64);
    // n > 5000
    EXPECT_NE(cephes::expn(5500, 10.0), nan64);
    // n <= 5000 && x > 1.0
    // cfrac: continued fraction
    EXPECT_NE(cephes::expn(10, 10.0), nan64);
    // Power series expansion
    EXPECT_NE(cephes::expn(1, 0.5), nan64);
    EXPECT_NE(cephes::expn(10, 0.5), nan64);
}
